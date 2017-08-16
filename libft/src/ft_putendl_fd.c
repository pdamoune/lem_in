/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:25:09 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:10:55 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Ecrit la chaine str sur le descripteur de fichier fd suivi d’un ’\n’.
*/

void	ft_putendl_fd(char const *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
