/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:30:29 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/25 15:40:31 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				j;
	unsigned const char	*s1;
	unsigned const char	*s2;

	i = 0;
	s1 = (unsigned const char*)haystack;
	s2 = (unsigned const char*)needle;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if ((i + j + 1) > len)
				return (0);
			if (s2[j + 1] == '\0')
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
