/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/01 21:27:28 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_solver(void)
{
	// int		len;

	ft_printf("\n========   SOLVER   ========\n");
	lem_set_weight(); // supprimer toute les salle = INT_MAX
	// lem_check_rooms to delete();
	lem_clr_path(g_rooms); // set weight met les salles a 1
	lem_get_paths();
	ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
