/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:22:42 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 12:30:29 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convptr(t_struct *t)
{
	t->hash = 1;
	t->width = (t->ast % 2 == 0 ? t->width : va_arg(t->ap, int));
	t->prec = (t->ast >= 0 ? t->prec : va_arg(t->ap, int));
	t->width = (t->width >= 0 ? t->width : t->width * -1);
	t->prec = (t->prec >= 0 ? t->prec : 0);
	t->lu = va_arg(t->ap, long unsigned int);
	if (t->lu == 0)// && t->dot == 1)
		t->tmp = ft_strdup("0");
	else
		t->tmp = ft_lhextoa(t->lu);
	ft_setflagshex(t);
	ft_convu(t);
	free(t->str);
}

void	ft_convper(t_struct *t)
{
	t->width = ((t->ast % 2) != 0 ? va_arg(t->ap, int) : t->width);
	if (t->sign >= 2)
		ft_putchar_fd('%', 1);
	while (t->width > 1)
	{
		ft_putchar_fd(t->sign == 1 ? '0' : ' ', 1);
		t->width--;
		t->charc++;
	}
	if (t->sign < 2)
		ft_putchar_fd('%', 1);
	t->charc = t->charc + 1;
	t->pos++;
}
