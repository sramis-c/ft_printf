/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convuns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:27:37 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 14:37:48 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convuns(t_struct *t)
{
	t->width = (t->ast % 2 == 0 ? t->width : va_arg(t->ap, int));
	t->prec = (t->ast >= 0 ? t->prec : va_arg(t->ap, int));
	t->width = (t->width >= 0 ? t->width : t->width * -1);
	t->prec = (t->prec >= 0 ? t->prec : 0);
	
	t->u = va_arg(t->ap, unsigned int);
	ft_setflagsu(t);
	ft_convu(t);

	free(t->str);
}

void	ft_setflagsu(t_struct *t)
{
	if (t->dot == 1 && t->u == 0)
		t->str = ft_strdup("");
	else
		t->str = ft_utoa(t->u >= 0 ? t->u : UINT_MAX + t->u);
	if (t->dot == 0 && t->sign == 1)
		t->prec = t->width - 1;
	if (t->prec < (int)ft_strlen(t->str))
		t->prec = ft_strlen(t->str);
	if (t->aps == 1 && t->sign < 2)
		t->width -= (ft_strlen(t->str) - 1) / 3;
}

void	ft_convu(t_struct *t)
{
	if (t->sign >= 2 && t->hash == 1 && t->dot == 1)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd((t->s[t->pos] == 'X' ? 'X' : 'x'), 1);
		t->charc += 2;
		t->prec += 2;
		t->width += 2;
	}
	ft_uns1(t);
	while (t->width > t->prec)
	{
		ft_putchar_fd((t->sign == 1 && t->dot != 1 ? '0' : ' '), 1);
		t->width--;
		t->charc++;
	}
	if (t->sign <= 1 && t->hash == 1 && (t->sign == 1 || t->dot == 1))
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd((t->s[t->pos] == 'X' ? 'X' : 'x'), 1);
		t->charc += 2;
		if (t->sign == 1 && t->dot == 0)
			t->prec -= 1;
	}
	ft_uns2(t);
	t->pos++;
}

void	ft_uns1(t_struct *t)
{
	t->k = 0;
	while (t->sign >= 2 && t->k++ + (int)ft_strlen(t->str) < t->prec)
	{
		ft_putchar_fd((t->sign == 1 || t->dot == 1 ? '0' : ' '), 1);
		t->charc++;
	}
	while (t->sign >= 2 && t->str[t->i])
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

void	ft_uns2(t_struct *t)
{
	while (t->sign <= 1 && t->prec-- > (int)ft_strlen(t->str))
	{
		ft_putchar_fd((t->sign == 1 || t->dot == 1 ? '0' : ' '), 1);
		t->charc++;
	}
	while (t->sign <= 1 && t->str[t->i])
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
