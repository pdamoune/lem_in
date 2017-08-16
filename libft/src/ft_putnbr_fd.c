/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:25:20 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:04 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Ecrit l’entier n sur le descripteur de fichier fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = (int)n;
	if (i < 0)
	{
		i = i * -1;
		ft_putchar_fd('-', fd);
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	if (i >= 10)
		i = i % 10;
	ft_putchar_fd(i + '0', fd);
}
