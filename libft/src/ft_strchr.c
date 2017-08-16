/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:17:07 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:30 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Searches for the first occurrence of the character c (an unsigned char) in
** the string pointed to by the argument str.
*/

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		i++;
		if (c == '\0' && str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
	}
	return (NULL);
}
