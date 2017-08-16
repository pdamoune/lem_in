/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_set_globales.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:41:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 19:13:28 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	lem_set_globales(void)
{
	g_data = NULL;
	g_rooms = NULL;
	g_paths = NULL;
	g_multiple_paths = NULL;
	g_ants_paths = NULL;
	g_visu = NULL;
	g_tmp = NULL;
	g_ants_end = NULL;
	g_ants = 0;
	g_nb_rooms = 0;
}
