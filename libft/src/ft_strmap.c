/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:58:25 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:17 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre pour créer une nouvelle chaine
** “fraiche” (avec malloc(3)) résultant des applications successives
** de f.
*/

char	*ft_strmap(const char *str, char (*f)(char))
{
	int		i;
	char	*dest;

	i = 0;
	if (!(str && f))
		return (NULL);
	if ((dest = ft_strdup(str)))
	{
		while (str[i])
		{
			dest[i] = (*f)(str[i]);
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
