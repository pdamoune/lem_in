/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:49:08 by philippe          #+#    #+#             */
/*   Updated: 2017/04/29 12:44:50 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_tabdel(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_strdel(&tab[i++]);
	ft_memdel((void **)&tab);
}
