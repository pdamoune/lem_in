/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_set_globales.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:41:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/13 04:02:47 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/lem_in.h"

void	lem_set_globales(void)
{
	g_data = NULL;
	g_rooms = NULL;
	g_paths = NULL;
	g_ants = 0;
}