/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:13:43 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:10:22 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Copies no more than n bytes from memory area src to memory area dest,
** stopping when the character c is found.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
