/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:04:35 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:06 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Affiche l’entier n sur la sortie standard.
*/

void	ft_putnbr(int n)
{
	long	i;

	i = (int)n;
	if (i < 0)
	{
		i = i * -1;
		ft_putchar('-');
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	if (i >= 10)
		i = i % 10;
	ft_putchar(i + '0');
}
