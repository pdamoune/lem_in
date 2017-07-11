/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:09:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/11 19:32:11 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void 		lem_free_data(t_list *data, t_list *rooms)
{
	t_list	*tmp;
	// t_list	*tmp1;
	t_list	*links;

	while (data)
	{
		ft_memdel(&data->content);
		tmp = data->next;
		free(data);
		data = tmp;
	}
	g_data = NULL;
	while (rooms)
	{
		ft_strdel(&(((t_room *)rooms->content)->name));
		links = ((t_room *)rooms->content)->links;
		while (links)
		{
			tmp = links->next;
			free(links);
			links = tmp;
		}
		ft_memdel(&rooms->content);
		tmp = rooms->next;
		free(rooms);
		rooms = tmp;
	}
	g_rooms = NULL;
}

void		lem_free(int err)
{
	err <= NEG_ANTS ? lem_free_data(g_data, g_rooms) : 0;
	exit (-1);
}
