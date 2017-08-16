/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:48:28 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de
** caractères passée en paramètre en précisant son index en premier
** argument. Chaque caractère est passé par adresse à la
** fonction f afin de pouvoir être modifié si nécéssaire.
*/

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (str && f)
		while (*str)
			(*f)(i++, &(*str++));
}
