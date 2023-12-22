/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:35:51 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 15:32:13 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

void	ft_checkconv(t_struct *t)
{
	if (t->s[t->pos] == 'c')
		ft_convcar(t);
	else if (t->s[t->pos] == 's')
		ft_convstr(t);
	else if (t->s[t->pos] == 'p')
		ft_convptr(t);
	else if (t->s[t->pos] == 'd' || t->s[t->pos] == 'i')
		ft_convdec(t);
	else if (t->s[t->pos] == 'u')
		ft_convuns(t);
	else if (t->s[t->pos] == 'x' || t->s[t->pos] == 'X')
		ft_convhex(t);
	else if (t->s[t->pos] == '%')
		ft_convper(t);
}

void	ft_convcar(t_struct *t)
{
	t->width = (t->ast == 1 ? va_arg(t->ap, int) : t->width);
	if (t->sign == 2)
		ft_putchar_fd(va_arg(t->ap, int), 1);
	if (t->width < 0)
		t->width *= -1;
	while (t->width > 1)
	{
		ft_putchar_fd(t->sign == 1 ? '0' : ' ', 1);
		t->width--;
		t->charc++;
	}
	if (t->sign != 2)
		ft_putchar_fd(va_arg(t->ap, int), 1);
	t->charc++;
	t->pos++;
}

void	ft_convstr(t_struct *t)
{
	t->width = ((t->ast % 2) != 0 ? va_arg(t->ap, int) : t->width);
	t->prec = (t->ast < 0 ? va_arg(t->ap, int) : t->prec);
	t->str = va_arg(t->ap, char*);
	t->str = t->str == NULL ? "(null)" : t->str;
	if (t->width < 0)
	{
		t->width *= -1;
		t->sign = 2;
	}
	if (t->dot == 0 || t->prec > (int)ft_strlen(t->str) || t->prec < 0)
		t->prec = ft_strlen(t->str);
	if (t->sign >= 2)
		while (t->str[t->p] && t->p < t->prec)
			ft_putchar_fd(t->str[t->p++], 1);
	while (t->width > t->prec)
	{
		ft_putchar_fd(t->sign == 1 ? '0' : ' ', 1);
		t->width--;
		t->charc++;
	}
	if (t->sign != 2)
		while (t->str[t->p] && (t->p < t->prec))
			ft_putchar_fd(t->str[t->p++], 1);
	t->charc += t->p;
	t->pos++;
}

void	ft_convdec(t_struct *t)
{
	t->width = (t->ast % 2 == 0 ? t->width : va_arg(t->ap, int));
	t->prec = (t->ast >= 0 ? t->prec : va_arg(t->ap, int));
	t->prec = (t->prec >= 0 ? t->prec : 0);
	t->sign = t->width < 0 ? 2 : t->sign;
	t->width = (t->width < 0 ? (t->width * -1) : t->width);

	t->p = va_arg(t->ap, int);
	ft_setflags(t);

	ft_convint(t);
	free(t->str);
}
