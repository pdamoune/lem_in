/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:24:06 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:53 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** returns a pointer to a new string which is a duplicate of the string s.
** Memory for the new string is obtained with malloc(3), and can be freed
** with free(3).
*/

char	*ft_strdup(const char *src)
{
	char	*a;
	int		n;

	n = 0;
	if ((a = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
	{
		while (src[n])
		{
			a[n] = src[n];
			n++;
		}
		a[n] = '\0';
		return (a);
	}
	return (NULL);
}
