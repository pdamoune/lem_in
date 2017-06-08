/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:44:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/30 15:26:00 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void 	lem_display(t_data *all_data, t_list *datas, t_list *rooms, t_list *links, int i)
{
	t_room	*room;
	t_link	*link;
	t_data	*data;

	if (i & (1 << 2))
	{
		ft_printf("\n      ---- datas ----\n\n");
		while (datas)
		{
			data = datas->content;
			ft_printf("name = |%s|\n", datas->content);
			datas = datas->next;
		}
		ft_printf("map[x] = |%d|\n", all_data->map[0]);
		ft_printf("map[y] = |%d|\n", all_data->map[1]);
	}

	if (i & (1 << 1))
	{
		ft_printf("\n      ---- rooms ----\n\n");
		while (rooms)
		{
			room = rooms->content;
			room->pos == 0 ? ft_printf("pos  = |%d|       x = %2d  /  y = %2d\n", room->pos, room->x, room->y) : 0;
			room->pos == 2 ? ft_printf("pos  = |START|   x = %2d  /  y = %2d\n", room->x, room->y) : 0;
			room->pos == 3 ? ft_printf("pos  = |END|     x = %2d  /  y = %2d\n", room->x, room->y) : 0;
			rooms = rooms->next;
		}
	}

	if (i & (1 << 0))
	{
		ft_printf("\n      ---- links ----\n\n");
		while (links)
		{
			link = links->content;
			ft_printf("room1 =  |%s - ", link->room1);
			ft_printf("%s|  = room2\n", link->room2);
			links = links->next;
		}
	}
	if (i & 1 << 3)
	{
		ft_printf("\n      ---- graph ----\n\n");

		int j = -1;
		while (all_data->graph[++j])
			ft_printf("|%s|\n", all_data->graph[j]);
	}
}
