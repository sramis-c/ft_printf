/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:32:43 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 19:31:54 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_struct
{
	const char					*s;
	va_list						ap;
	int							sign;
	int							dot;
	int							width;
	int							prec;
	int							hash;
	int							spc;
	int							ast;
	int							aps;
	int							pos;
	int							p;
	unsigned int				u;
	long int					l;
	long long int				ll;
	long unsigned int			lu;
	long long unsigned int		llu;
	char						*str;
	char						*tmp;
	int							charc;
	int							i;
	int							j;
	int							k;
}				t_struct;
int				ft_printf(const char *s, ...);
void			ft_checkflags(t_struct *t);
void			ft_checksign(t_struct *t);
void			ft_checkfield(t_struct *t);
void			ft_checkfield2(t_struct *t);
void			ft_checkmod(t_struct *t);
void			ft_checkconv(t_struct *t);
void			ft_setflags(t_struct *t);
void			ft_setflags2(t_struct *t);
void			ft_setflagsl(t_struct *t);
void			ft_setflagsll(t_struct *t);
void			ft_setflagsu(t_struct *t);
void			ft_setflagslu(t_struct *t);
void			ft_setflagsllu(t_struct *t);
void			ft_setflagshex(t_struct *t);
void			ft_setflagshex2(t_struct *t);
void			ft_convcar(t_struct *t);
void			ft_convstr(t_struct *t);
void			ft_convptr(t_struct *t);
void			ft_convdec(t_struct *t);
void			ft_convint(t_struct *t);
void			ft_int1(t_struct *t);
void			ft_int2(t_struct *t);
void			ft_convuns(t_struct *t);
void			ft_convu(t_struct *t);
void			ft_uns1(t_struct *t);
void			ft_uns2(t_struct *t);
void			ft_convhex(t_struct *t);
void			ft_convlong(t_struct *t);
void			ft_convper(t_struct *t);
void			ft_clearflags(t_struct *t);
#endif
