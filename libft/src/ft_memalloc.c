/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:25:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 17:03:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une zone de mémoire
** “fraiche”. La mémoire allouée est initialisée à 0. Si l’allocation
** échoue, la fonction renvoie NULL.
*/

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return ((void *)mem);
}
