/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:54:17 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:24 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** The strcat() function appends the src string to the dest string, overwriting
** the terminating null byte ('\0') at the end of dest, and then adds a
** terminating null byte. The strings may not overlap, and the dest string must
** have enough space for the result. If dest is not large enough, program
** behavior is unpredictable; buffer overruns are a favorite avenue for
** attacking secure programs.
** The strncat() function is similar, except that
** *
** It will use at most n bytes from src; and
** *
** src does not need to be null-terminated if it contains n or more bytes.
** As with strcat(), the resulting string in dest is always null-terminated.
** If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from
** src plus the terminating null byte). Therefore, the size of dest must be at
** least strlen(dest)+n+1.
*/

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	j;

	j = 0;
	while (dest[j])
		j++;
	while (*src && n)
	{
		dest[j++] = *src++;
		n--;
	}
	dest[j] = '\0';
	return (dest);
}
