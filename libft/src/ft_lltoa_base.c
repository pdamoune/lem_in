/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:30:35 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/27 10:29:23 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_lltoa_base(long long n, unsigned int base)
{
	char		result[64];
	int			len;
	int			mod;

	len = 0;
	ft_bzero(result, 21);
	result[len] = '0';
	while (n > 0 || n < 0)
	{
		mod = ABS(n % base);
		result[len] = mod + '0';
		if (base >= 10)
			if (!ft_isdigit(result[len]))
				result[len] += 39;
		if (n / base == 0 && n < 0)
			result[len + 1] = '-';
		n /= base;
		len++;
	}
	ft_strrev(result);
	return (ft_strdup(result));
}
