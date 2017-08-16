/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:26:03 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractère
** “fraiche” terminée par un ’\0’. Chaque caractère de la chaine
** est initialisé à ’\0’. Si l’allocation echoue, la fonction renvoie
** NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char *) * size + 1)))
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
