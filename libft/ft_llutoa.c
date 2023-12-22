/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:22:10 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 13:42:37 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		ft_llulen(long long unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = ULLONG_MAX - n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_llutoa(long long unsigned int n)
{
	int						i;
	long long unsigned int	nb;
	char					*num;

	nb = n;
	i = ft_llulen(nb);
	num = malloc((i + 1) * sizeof(char));
	if (!(num))
		return (0);
	num[i] = '\0';
	num[0] = '0';
	if (nb < 0)
		nb = ULLONG_MAX - n;
	while (i-- >= 0)
	{
		if (nb > 0)
			num[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (num);
}
