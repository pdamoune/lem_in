/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/08 19:04:54 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_solver(void)
{
	// int		len ;

	// ft_printf("\n========   SOLVER   ========\n");
	lem_set_weight(); // supprimer toute les salle = INT_MAX
	if (lem_get_start(g_rooms)->weight == INT_MAX)
		return (ft_error(1, ST_END, INFO, "No possible paths", &lem_free));

	// lem_display(1, "rooms");
	lem_clr_path(g_rooms); // set weight met les salles a 1
	lem_get_paths();

	// lem_display(1, "rooms");

	// lem_display(1, "multiple");

	// ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
