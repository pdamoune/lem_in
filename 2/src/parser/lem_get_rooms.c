/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:30:45 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/11 19:13:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_set_room(t_room *room)
{
	!g_rooms ? g_rooms = ft_lstptr(room) :
	ft_lstadd_last(&g_rooms, ft_lstptr(room));
	return (room->position);
}

int 	lem_set_com(char *line, int *pos)
{
	int		com;

	if ((com = lem_is_com(line)))
	{
		if (com > 1)
			*pos = com - 1;
		return (com);
	}
	return (0);
}

int		lem_get_rooms(void)
{
	t_list	*data;
	t_room	*room;
	short	start_end;

	start_end = 4;
	data = g_data;
	while (data && lem_is_com(data->content) > 0)
		data = data->next;
	room = ft_memalloc(sizeof(t_room));
	while ((data = data->next))
	{
		if (lem_set_com(data->content, &room->position))
			continue ;
		if (lem_is_room(room, data->content))
			start_end |= lem_set_room(room);
		else if (lem_is_link(data->content))
		{
			free(room);
		}
		else
			break ;



		room = ft_memalloc(sizeof(t_room));

		// }
		//  && !lem_is_link(room, data->content))
			// ft_printf("On fait avec ce qu on a, break ?\n");
	}
	free(room);
	if (~(start_end & ST_END) & ST_END)
		return (ft_error(1, ST_END, INFO, "Missing start or end", &lem_free));
	return (1);
}
