/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:00:18 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/09 18:43:07 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_get_graph(t_data *data, t_list *rooms, t_list *links)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	x = data->map[0] + 1;
	y = data->map[1] + 1;
	data->graph = ft_memalloc(sizeof(char *) * y);
	while (++i < y)
		(data->graph[i] = ft_memalloc(x)) && ft_memset(data->graph[i], ' ', x);
	i = 0;
	while (rooms)
	{
		x = ((t_room *)rooms->content)->x;
		y = ((t_room *)rooms->content)->y;
		ft_strncpy(&data->graph[y][x], ((t_room *)rooms->content)->name, 1);
		rooms = rooms->next;

	}
	(void)&rooms;
	(void)&links;
	return (0);
}


int		lem_parsing(t_data *data)
{
	t_error		error;

	ft_bzero(&error, sizeof(t_error));
	ft_printf("\n======== PARSING ========\n");
	if ((error.gnl = lem_get_data(&data->list_data)) < 1)
		lem_error(&error);
	if ((error.ants = lem_get_ants(data->list_data, &data->ants)) < 1)
		lem_error(&error);
	if ((error.rooms = lem_get_rooms(data, data->list_data, &data->list_rooms)) < 3)
		lem_error(&error);
	if (!(error.links = lem_get_links(data, data->list_data, data->list_rooms, &data->list_links)))
		lem_error(&error);
	lem_get_graph(data, data->list_rooms, data->list_links);
	ft_printf("=========================\n");
	return (1);
}
