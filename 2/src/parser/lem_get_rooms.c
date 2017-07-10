/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:30:45 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/10 19:03:05 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

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

int		lem_get_rooms(void)
{
	t_list	*data;
	t_room	*room;

	data = g_data;
	while (data && lem_is_com(data->content) > 0)
		data = data->next;
	room = ft_memalloc(sizeof(t_room));
	while ((data = data->next))
	{
		if (lem_set_com(data->content, &room->position))
			continue ;
		if (!lem_is_room(room, data->content))
			ft_printf("pas room = %s\n", data->content);
		else
			ft_printf("Room = %s\n", data->content);
		//  && !lem_is_link(room, data->content))
			// ft_printf("On fait avec ce qu on a, break ?\n");




	}
	return (1);
}
