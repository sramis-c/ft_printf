/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:12:35 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/08 17:45:16 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*strn;
	size_t	i;

	i = 0;
	strn = (char *)str;
	while (n > i)
	{
		strn[i] = '\0';
		i++;
	}
}