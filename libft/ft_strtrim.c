/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:00:07 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/19 19:14:55 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findpos(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s2[j] != s1[i])
		{
			j++;
		}
		if (!(s2[j]))
			return (i);
		i++;
	}
	return (0);
}

int		ft_findrpos(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	while (i > 0)
	{
		i--;
		j = 0;
		while (s2[j] && s2[j] != s1[i])
		{
			j++;
		}
		if (!(s2[j]))
			return (i + 1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		x;
	int		y;
	int		z;
	int		i;

	if (!(s1) || !(set))
		return (NULL);
	i = 0;
	x = ft_findpos(s1, set);
	y = ft_findrpos(s1, set);
	z = (y - x);
	str = malloc((z + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	while (i < z)
	{
		str[i] = s1[i + x];
		i++;
	}
	str[i] = '\0';
	return (str);
}
