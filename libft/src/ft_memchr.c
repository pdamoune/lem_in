/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:07:45 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:10:25 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Scans the initial n bytes of the memory area pointed to by s for the first
** instance of c. Both c and the bytes of the memory area pointed to by s are
** interpreted as unsigned char.
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return (&(((void *)str)[i]));
		i++;
	}
	return (NULL);
}
