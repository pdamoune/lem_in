/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:47:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:13:09 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine
** passée en paramètre sans les espaces blancs au debut et à la
** fin de cette chaine. On considère comme espaces blancs les
** caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
** blancs au début ou à la fin, la fonction renvoie une copie de
** s. Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strtrim(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	j = ft_strlen(str) - 1;
	while ((str[i] == '\n' || ft_isblank(str[i]) == 1) && *str)
		i++;
	while ((str[j] == '\n' || ft_isblank(str[j]) == 1) && j)
		j--;
	if (j == 0)
		return (ft_strdup(""));
	return (ft_strsub(str, i, (j - i + 1)));
}
