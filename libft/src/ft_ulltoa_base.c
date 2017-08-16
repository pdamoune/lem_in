/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:30:33 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/08 19:34:28 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_ulltoa_base(unsigned long long n, unsigned int base)
{
	char		result[64];
	int			len;

	if (base == 2 || base == 8 || base == 16)
		n = (unsigned)n;
	len = 0;
	ft_bzero(result, 65);
	result[len] = '0';
	while (n > 0)
	{
		result[len] = n % base + '0';
		if (base >= 10)
			if (!ft_isdigit(result[len]))
				result[len] += 39;
		n /= base;
		len++;
	}
	ft_strrev(result);
	return (ft_strdup(result));
}
