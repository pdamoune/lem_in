/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 04:43:27 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:42 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** finds the first occurrence of the substring needle in the string haystack.
** when the caractere c is found in needle, it compares the next caractere
** The terminating null bytes ('\0') are not compared.
** The function returns the adress of the first occurence in haystack
*/

char	*ft_strcstr(const char *haystack, const char *needle, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j] || needle[j] == c)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
