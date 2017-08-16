/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:14:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/08 19:26:38 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Affiche le nombre n en binaire.
*/

void	ft_putbin_base(int n, int base)
{
	int i;

	i = base;
	while (--i >= 0)
	{
		(1 << i) & n ? ft_putchar('1') : ft_putchar('0');
		if (i % 8 == 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
