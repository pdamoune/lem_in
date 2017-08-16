/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:21:23 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/27 10:26:29 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères
** “fraiche” terminée par un ’\0’ résultant de la concaténation
** de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL
*/

char	*ft_strjoin(char *str1, const char *str2)
{
	char	*s;
	size_t	len;

	len = ft_strlen(str1) + ft_strlen(str2);
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(s, str1);
	ft_strcpy(&s[ft_strlen(str1)], str2);
	s[len] = '\0';
	return (s);
}
