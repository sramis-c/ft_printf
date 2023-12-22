/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:19:29 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/14 16:28:11 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	char		*source;
	size_t		i;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (dest == NULL && source == NULL)
		return (dst);
	if (src > dst)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else if (src < dst)
	{
		i = len;
		while (i-- > 0)
			dest[i] = source[i];
	}
	return (dst);
}
