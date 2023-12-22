/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:39:24 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/22 16:22:44 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		return(1);
		//n = UINT_MAX - n;
	}
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_hextoa(unsigned int n)
{
	int				i;
	unsigned int	nb;
	char			*num;

	nb = n;
	i = ft_hexlen(nb);
	num = malloc((i + 1) * sizeof(char));
	if (!(num))
		return (0);
	num[i] = '\0';
	num[0] = '0';
	if (nb < 0)
		nb = UINT_MAX - n;
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
