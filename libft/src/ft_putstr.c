/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:49:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/06 12:11:09 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Affiche la chaine str sur la sortie standard.
*/

void	ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
