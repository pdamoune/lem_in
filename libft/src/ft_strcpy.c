/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:41:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/20 10:12:24 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Copies the string pointed to by src, including the terminating null byte
** ('\0'), to the buffer pointed to by dest. The strings may not overlap,
** and the destination string dest must be large enough to receive the copy.
** Beware of buffer overruns! (See BUGS.)
*/

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	if (!src)
		return (dest);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
