/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:40:40 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/06 00:34:21 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Copies n bytes from memory area src to memory area
** dest. The memory areas may overlap: copying takes place as though the bytes
** in src are first copied into a temporary array that does not overlap src or
** dest, and the bytes are then copied from the temporary array to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
