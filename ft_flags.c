/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:20:08 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 15:07:35 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_checkflags(t_struct *t)
{
	ft_clearflags(t);
	ft_checksign(t);
	ft_checkfield(t);
	ft_checkconv(t);
}

void	ft_checksign(t_struct *t)
{
	while (t->s[t->pos] == '0' || t->s[t->pos] == ' ' ||
			t->s[t->pos] == '-' || t->s[t->pos] == '+')
	{
		if (t->s[t->pos] == '0')
			t->sign = (t->sign >= 2 ? 3 : 1);
		else if (t->s[t->pos] == ' ')
			t->spc = (t->spc >= 2 ? 3 : 1);
		else if (t->s[t->pos] == '-')
			t->sign = 2;
		else if (t->s[t->pos] == '+')
			t->spc = 2;
		t->pos++;
	}
	while (t->s[t->pos] == 39 || t->s[t->pos] == '#')
	{
		if (t->s[t->pos] == 39)
			t->aps = 1;
		else if (t->s[t->pos] == '#')
			t->hash = 1;
		t->pos++;
	}
	if (t->s[t->pos] == '-' || t->s[t->pos] == '0' ||
		t->s[t->pos] == ' ' || t->s[t->pos] == '+' || t->s[t->pos] == '#')
		ft_checksign(t);
}

void	ft_checkfield(t_struct *t)
{
	if (t->s[t->pos] == '*')
	{
		t->ast = 1;
		t->pos++;
	}
	while (t->s[t->pos] >= '0' && t->s[t->pos] <= '9')
		t->width = (t->width * 10) + (t->s[t->pos++] - '0');
	while (t->s[t->pos] == '.')
	{
		t->pos++;
		t->dot = 1;
	}
	ft_checkfield2(t);
}

void	ft_checkfield2(t_struct *t)
{
	if (t->dot == 1)
	{
		if (t->s[t->pos] == '*')
		{
			t->ast = t->ast - 4;
			t->pos++;
		}
		while (t->s[t->pos] >= '0' && t->s[t->pos] <= '9')
		{
			t->prec = (t->prec * 10) + (t->s[t->pos] - '0');
			t->pos++;
		}
	}
	if (t->s[t->pos] == '.')
	{
		t->prec = 0;
		ft_checkfield(t);
	}
	if (t->s[t->pos] == '-' || t->s[t->pos] == '0' ||
		t->s[t->pos] == ' ' || t->s[t->pos] == '+' || t->s[t->pos] == '#')
		ft_checksign(t);
}