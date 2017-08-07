/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:43:33 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/07 18:16:55 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_parser(void)
{
	// ft_printf("\n========   PARSING   ========\n");
	lem_get_data();
	// if (!g_data)
	// 	return (-1);
	lem_get_ants(g_data);
	g_nb_rooms = lem_get_rooms();
	// ft_printf("\n======== FIN PARSING ========\n");
	return (0);
}
