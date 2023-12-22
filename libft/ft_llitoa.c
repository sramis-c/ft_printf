/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:51:03 by sramis-c          #+#    #+#             */
/*   Updated: 2020/01/19 18:27:56 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_llilen(long int n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_llitoa(long long int n)
{
	int				i;
	long long int	nb;
	char			*num;

	nb = n;
	i = ft_llilen(nb);
	num = malloc((i + 1) * sizeof(char));
	if (!(num))
		return (0);
	num[i] = '\0';
	num[0] = '0';
	if (nb < 0)
		nb *= -1;
	while (i-- >= 0)
	{
		if (nb > 0)
			num[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}
