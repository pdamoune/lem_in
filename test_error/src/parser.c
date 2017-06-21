/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:39:27 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 19:32:20 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	lem_parser(void)
{
	t_data		*data;

	data = v_data();
	ft_printf("\n======== PARSING ========\n");
	lem_get_data();
	lem_get_ants(data->list_data);
	// lem_get_rooms(void);
	// lem_get_links(void);
	ft_printf("=========================\n");

}
