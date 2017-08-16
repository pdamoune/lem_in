/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:47:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:45 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine
** passée en paramètre sans le caractere c en debut ou fin de ligne.
*/

char	*ft_strctrim(const char *str, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	j = ft_strlen(str) - 1;
	while (str[i] == c && str[i])
		i++;
	while (str[j] == c && j > 0)
		j--;
	if (j == 0)
		return (ft_strdup(""));
	return (ft_strsub(str, i, (j - i + 1)));
}
