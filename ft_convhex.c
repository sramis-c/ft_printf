/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:45:09 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 12:54:12 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convhex(t_struct *t)
{
	t->width = (t->ast % 2 == 0 ? t->width : va_arg(t->ap, int));
	t->prec = (t->ast >= 0 ? t->prec : va_arg(t->ap, int));
	t->width = (t->width >= 0 ? t->width : t->width * -1);
	t->prec = (t->prec >= 0 ? t->prec : 0);

	t->u = va_arg(t->ap, unsigned int);
	t->tmp = ft_hextoa(t->u >= 0 ? t->u : UINT_MAX + t->u);
	ft_setflagshex(t);

	ft_convu(t);
	free(t->str);
}

void	ft_setflagshex(t_struct *t)
{
	if (t->u == 0 && t->lu == 0 && t->llu == 0 && t->s[t->pos] != 'p')
		t->hash = 0;
	if (t->hash == 1 && t->prec <= (int)ft_strlen(t->tmp) &&
		(t->sign != 1 || t->width <= (int)ft_strlen(t->tmp)))
	{
		t->str = ft_strjoin((t->s[t->pos] == 'X' ? "0X" : "0x"), t->tmp);
		t->hash = 2;
	}
	else if (t->dot == 1 && t->u == 0 && t->lu == 0 && t->llu == 0
			&& t->s[t->pos] != 'p')
		t->str = ft_strdup("");
	else
		t->str = ft_strdup(t->tmp);
	free(t->tmp);
	ft_setflagshex2(t);
}

void	ft_setflagshex2(t_struct *t)
{
	if (t->dot == 0 && t->sign == 1)
		t->prec = t->width - 1;
	if (t->prec < (int)ft_strlen(t->str))
		t->prec = ft_strlen(t->str);
	if (t->aps == 1 && t->sign < 2)
		t->width -= (ft_strlen(t->str) - 1) / 3;
	if (t->hash == 1)
		t->width -= 2;
	if (t->s[t->pos] == 'X')
		while (t->str[t->j])
		{
			if (t->str[t->j] >= 97 && t->str[t->j] <= 122)
				t->str[t->j] -= (char)32;
			t->j++;
		}
}
