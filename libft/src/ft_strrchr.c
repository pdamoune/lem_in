/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:48 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Searches for the last occurrence of the character c (an unsigned char) in
** the string pointed to, by the argument str.
*/

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (((char *)str)[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (&((char *)str)[i]);
		i--;
	}
	return (0);
}
