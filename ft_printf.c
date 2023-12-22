/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:51:39 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 13:35:03 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *s, ...)
{
	t_struct	*t;
	int			ret;

	t = ft_calloc(1, sizeof(t_struct));
	t->s = s;
	va_start(t->ap, s);
	while (t->s[t->pos] != '\0')
	{
		if (t->s[t->pos] == '%')
		{
			t->pos++;
			ft_checkflags(t);
		}
		else
		{
			ft_putchar_fd(t->s[t->pos], 1);
			t->pos++;
			t->charc++;
		}
	}
	ret = t->charc;
	free(t);
	return (ret);
}

void	ft_clearflags(t_struct *t)
{
	t->sign = 0;
	t->dot = 0;
	t->width = 0;
	t->prec = 0;
	t->hash = 0;
	t->spc = 0;
	t->ast = 0;
	t->aps = 0;
	t->p = 0;
	t->l = 0;
	t->ll = 0;
	t->lu = 0;
	t->llu = 0;
	t->str = 0;
	t->tmp = 0;
	t->i = 0;
	t->j = 0;
	t->k = 0;
}