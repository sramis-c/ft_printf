/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:09:46 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/23 20:48:15 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	s3 = malloc(sizeof(char) * (i + j) + 1);
	if (!(s3))
		return (NULL);
	s3[i + j] = '\0';
	while (j >= 0)
	{
		s3[i + j] = s2[j];
		j--;
	}
	i--;
	while (i >= 0)
	{
		s3[i] = s1[i];
		i--;
	}
	return (s3);
}
