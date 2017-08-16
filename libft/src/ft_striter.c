/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:35:27 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de
** caractères passée en paramètre. Chaque caractère est passé
** par adresse à la fonction f afin de pouvoir être modifié si
** nécéssaire.
*/

void	ft_striter(char *str, void (*f)(char *))
{
	if (str && f)
		while (*str)
			(*f)(&(*str++));
}
