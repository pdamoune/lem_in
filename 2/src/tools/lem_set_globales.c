/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_set_globales.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:41:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/20 17:26:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/lem_in.h"

void	lem_set_globales(void)
{
	g_data = NULL;
	g_rooms = NULL;
	g_paths = NULL;
	g_multiple_paths = NULL;
	g_ants = 0;
}
