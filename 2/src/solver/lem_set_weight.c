/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_set_weight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 12:24:03 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/01 12:40:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static void	lem_weight(t_list *links, t_room *room)
{
	static int	i = 1;

	while (links)
	{
		room = links->content;
		if (room->position == END - 1)
			room->weight = 0;
		if (room->position < END - 1 && (room->weight > i || !room->busy))
		{
			room->busy = 1;
			room->weight = i;
			i++;
			if (room->position < START - 1)
				lem_weight(room->links, room);
			i--;
		}
		links = links->next;
	}
}

void 	lem_set_weight()
{
	t_room	*room;

	room = lem_get_end(g_rooms);
	lem_weight(room->links, room);
}
