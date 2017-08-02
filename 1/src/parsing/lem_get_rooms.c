/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 21:44:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/02 14:29:30 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_set_room(t_list **list_rooms, t_room *room, int ret)
{
	t_list	*tmp;
	static int rm_nb = 0;

	tmp = ft_lstptr(room);
	!*list_rooms ? *list_rooms = tmp : (void)ft_lstadd_last(list_rooms, tmp);
	if (room->pos)
	{
		if (START - 1 & (room->pos - 1 & ret))
		{
			ft_lstclr_last(list_rooms);
			return (-1);
		}
		if (END - 1 & (room->pos - 1 & ret))
		{
			ft_lstclr_last(list_rooms);
			return (-2);
		}
		room->rm_nb = rm_nb++;
		return (room->pos - 1);
	}
	room->rm_nb = rm_nb++;
	return (0);
}

int 	lem_set_com(char *line, int *pos)
{
	int		com;

	if ((com = lem_is_com(line)))
	{
		if (com > 1)
			*pos = com;
		return (com);
	}
	return (0);
}

int		lem_get_rooms(t_data *data, t_list *list_data, t_list **list_rooms)
{
	t_room	*room;
	char	*line;
	t_link	link;
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	room = ft_memalloc(sizeof(t_room));
	while ((list_data = list_data->next))
	{
		if (lem_set_com(list_data->content, &room->pos))
			continue ;
		i++;
		if (!i)
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
