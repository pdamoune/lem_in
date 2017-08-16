/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:16:21 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:08 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Affiche la chaine s sur la sortie standard suivi d’un ’\n’.
*/

void	ft_putnbrel(int nb)
{
	ft_putnbr(nb);
	ft_putchar('\n');
}
