/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:52:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:58 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** finds the first occurrence of the substring needle in the string haystack.
** The terminating null bytes ('\0') are not compared.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
			{
				needle = haystack + i;
				return ((char *)needle);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
