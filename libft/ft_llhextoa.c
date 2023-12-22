/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llhextoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:30:02 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/24 13:41:55 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		ft_llhexlen(long long unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = ULLONG_MAX - n;
	}
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_llhextoa(long long unsigned int n)
{
	int						i;
	long long unsigned int	nb;
	char					*num;

	nb = n;
	i = ft_llhexlen(nb);
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
		{
			if (nb % 16 < 10)
				num[i] = (nb % 16) + '0';
			else
				num[i] = (nb % 16) + 87;
		}
		nb = nb / 16;
	}
	return (num);
}
