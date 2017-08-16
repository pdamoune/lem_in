/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:27:21 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:27 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Appends the src string to the dest string, overwriting the terminating null
** byte ('\0') at the end of dest, and then adds a terminating null byte. The
** strings may not overlap, and the dest string must have enough space for the
** result. If dest is not large enough, program behavior is unpredictable;
** buffer overruns are a favorite avenue for attacking secure programs
*/

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}
