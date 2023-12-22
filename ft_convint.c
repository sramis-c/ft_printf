/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:07:34 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 12:55:33 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setflags(t_struct *t)
{
	if (t->dot == 1 && t->p == 0)
		t->str = ft_strdup("");
	else if (t->p == INT_MIN)
		t->str = ft_strdup("2147483648");
	else
		t->str = ft_itoa(t->p >= 0 ? t->p : t->p * -1);
	ft_setflags2(t);
}

void	ft_setflags2(t_struct *t)
{
	if (t->dot == 0 && t->sign == 1)
		t->prec = t->width - 1;
	if (t->prec < (int)ft_strlen(t->str))
		t->prec = ft_strlen(t->str);
	if (t->aps == 1 && t->sign < 2)
		t->width -= (ft_strlen(t->str) - 1) / 3;
	if (t->p >= 0)
	{
		if (t->spc == 1)
		{
			ft_putchar_fd(' ', 1);
			t->charc++;
		}
		if (t->sign >= 2 && t->spc >= 1)
			t->prec++;
		if (t->sign < 2 && t->spc >= 1)
			t->width--;
	}
	else
		t->width--;
}

void	ft_convint(t_struct *t)
{
	if (t->sign >= 2)
		ft_int1(t);
	while (t->width > t->prec)
	{
		ft_putchar_fd((t->sign == 1 && t->dot != 1 ? '0' : ' '), 1);
		t->width--;
		t->charc++;
	}
	if (t->sign <= 1)
		ft_int2(t);
	if (t->p < 0)
		t->charc++;
	t->pos++;
}

void	ft_int1(t_struct *t)
{
	if (t->p < 0)
		ft_putchar_fd('-', 1);
	else if (t->spc >= 2)
	{
		ft_putchar_fd('+', 1);
		t->charc++;
	}
	t->k = 0;
	while ((int)ft_strlen(t->str) + t->k++ < t->prec)
	{
		if (t->sign == 1 || t->dot == 1)
		{
			ft_putchar_fd('0', 1);
			t->charc++;
		}
	}
	while (t->str[t->i])
	{
		if ((ft_strlen(t->str) - t->i) % 3 == 0 && t->i != 0 && t->aps == 1)
		{
			ft_putchar_fd(',', 1);
			t->charc++;
			t->prec++;
		}
		ft_putchar_fd(t->str[t->i++], 1);
		t->charc++;
	}
}

void	ft_int2(t_struct *t)
{
	if (t->p < 0)
		ft_putchar_fd('-', 1);
	else if (t->spc >= 2)
	{
		ft_putchar_fd('+', 1);
		t->charc++;
	}
	while (t->prec-- > (int)ft_strlen(t->str))
	{
		ft_putchar_fd((t->sign == 1 || t->dot == 1 ? '0' : ' '), 1);
		t->charc++;
	}
	while (t->str[t->i])
	{
		if ((ft_strlen(t->str) - t->i) % 3 == 0 && t->i != 0 && t->aps == 1)
		{
			ft_putchar_fd(',', 1);
			t->charc++;
		}
		ft_putchar_fd(t->str[t->i++], 1);
		t->charc++;
	}
}
