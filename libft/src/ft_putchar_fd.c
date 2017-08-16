/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:24:57 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:10:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Ecrit le caractère c sur le descripteur de fichier fd.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
