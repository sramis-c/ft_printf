/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:01:26 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/25 15:41:53 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	car;

	i = 0;
	str = (char*)s;
	car = (char)c;
	while (str[i] != '\0')
		i++;
	while (str[i] != car && i > 0)
		i--;
	if (str[i] == car)
		return (str + i);
	return (NULL);
}
