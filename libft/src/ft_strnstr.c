/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:05:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:41 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Locates the first occurrence of the null-
** terminated string little in the string big, where not more than len
** characters are searched.  Characters that appear after a `\0' character
** are not searched.  Since the strnstr() function is a FreeBSD specific
** API, it should only be used when portability is not a concern.
*/

char	*ft_strnstr(const char *haystack, const char *ndl, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ndl[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i + j < len)
	{
		while (ndl[j] == haystack[i + j] && i + j < len)
		{
			if (ndl[j + 1] == '\0')
			{
				ndl = haystack + i;
				return ((char *)ndl);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
