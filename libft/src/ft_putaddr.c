/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 05:07:44 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/24 04:35:10 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** affiche l adresse d un pointeur a l ecran
*/

void	ft_putaddr(void *ptr)
{
	ft_putstr("0x");
	ft_putstr(ft_ulltoa_base((unsigned long long)ptr, 16));
	ft_putendl("");
}
