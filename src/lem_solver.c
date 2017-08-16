/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 17:37:17 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_solver(void)
{
	lem_set_weight();
	if (lem_get_start(g_rooms)->weight == INT_MAX)
		return (ft_error(1, ST_END, INFO, "No possible paths", &lem_free));
	lem_clr_path(g_rooms);
	lem_get_paths();
	lem_set_paths(g_ants);
	return (0);
}
