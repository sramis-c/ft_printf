/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:05:55 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/21 18:42:49 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*str;

	if (!(s))
		return (0);
	i = ft_strlen(s);
	j = 0;
	str = malloc((i + 1) * sizeof(char));
	if (!(str))
		return (0);
	while (j < i)
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[i] = '\0';
	return (str);
}
