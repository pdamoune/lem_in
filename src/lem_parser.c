/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:43:33 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 17:54:20 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_parser(void)
{
	lem_get_data();
	lem_get_ants(g_data);
	if (g_ants < (INT_MAX / 4))
		g_ants_end = ft_memalloc((sizeof(int) * (g_ants + 1)));
	g_nb_rooms = lem_get_rooms();
	return (0);
}
