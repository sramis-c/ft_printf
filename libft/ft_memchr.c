/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:54:15 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/14 16:30:45 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	caracter;
	size_t	i;

	i = 0;
	string = (char *)s;
	caracter = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == caracter)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
