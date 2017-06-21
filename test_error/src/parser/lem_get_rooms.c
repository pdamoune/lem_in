/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 19:52:09 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 20:07:44 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_get_rooms(t_list *list_data)
{
	t_room	*room;
	char	*line;
	t_link	link;
	int		ret;

	ret = 0;
	room = ft_memalloc(sizeof(t_room));
	while ((list_data = list_data->next))
	{
		if (lem_set_com(list_data->content, &room->pos))
			continue ;
		if (lem_is_room(data, room, (line = ft_strdup(list_data->content))))
		{
			if ((ret |= lem_set_room(list_rooms, room, ret)) < 0)
				return (ret);
			
			room = ft_memalloc(sizeof(t_room));
			continue ;
		}
		ft_strdel(&line);
		if (!lem_is_link(*list_rooms, &link, list_data->content))
			return (-3);
	}
	return (ret);
}
