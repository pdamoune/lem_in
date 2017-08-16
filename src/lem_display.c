/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:46:24 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 17:43:57 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	lem_display_data(t_list *data)
{
	if (!data)
		return ;
	while (data)
	{
		ft_printf("%s\n", data->content);
		data = data->next;
	}
	ft_printf("\n");
}

void	lem_display(int visual)
{
	lem_display_data(g_data);
	lem_set_visual(g_ants_paths, NULL, NULL, NULL);
	if (visual)
	{
		lem_display_rooms(g_rooms);
		lem_display_multiple(g_multiple_paths);
	}
	lem_clr_path(g_rooms);
	lem_display_visual(visual, g_visu, NULL, NULL);
}
