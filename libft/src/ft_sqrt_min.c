/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:33:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:21 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Renvoie la racine carrée entière d’un nombre si elle existe,
** 0 si la racine carrée n’est pas entière.
*/

int	ft_sqrt_min(int nb)
{
	int	n;

	n = 1;
	while (nb != n++ && nb > 0)
		if (nb <= n * n)
			return (n);
	return (0);
}
