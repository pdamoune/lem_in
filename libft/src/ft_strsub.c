/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:00:24 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:13:04 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un
** tronçon de la chaine de caractères passée en paramètre. Le
** tronçon commence à l’index start et à pour longueur len. Si
** start et len ne désignent pas un tronçon de chaine valide,
** le comportement est indéterminé. Si l’allocation échoue, la
** fonction renvoie NULL.
*/

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (str)
	{
		if ((dest = (char *)malloc((sizeof(char) * len) + 1)))
		{
			while (i < len)
				dest[i++] = str[start++];
			dest[i] = '\0';
			return (dest);
		}
	}
	return (NULL);
}
