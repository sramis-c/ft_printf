/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:40:32 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/25 15:49:19 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	*destin;
	unsigned char	*source;

	destin = (unsigned char*)dest;
	source = (unsigned char*)src;
	i = 0;
	while (i < size)
	{
		if (source[i] == (unsigned char)c)
		{
			destin[i] = source[i];
			return (destin + i + 1);
		}
		destin[i] = source[i];
		i++;
	}
	return (0);
}
