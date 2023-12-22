/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:38:14 by sramis-c          #+#    #+#             */
/*   Updated: 2019/11/25 15:38:21 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cad;
	unsigned char	*cad1;

	cad = (unsigned char*)s1;
	cad1 = (unsigned char*)s2;
	i = 0;
	while (i < n && cad[i] == cad1[i])
		i++;
	if (i == n)
		return (0);
	if (cad[i] != cad1[i])
		return (cad[i] - cad1[i]);
	else
		return (0);
}
