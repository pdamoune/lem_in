/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_bin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:14:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/08 19:28:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Affiche le nombre n en binaire.
*/

void	ft_putfloat_bin(int n)
{
	int i;

	i = 31;
	(1 << 31) & n ? ft_putchar('1') : ft_putchar('0');
	ft_putchar(' ');
	while (--i >= 0)
	{
		(1 << i) & n ? ft_putchar('1') : ft_putchar('0');
		if (i % 8 + 1 == 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
