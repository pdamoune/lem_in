/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:11:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/20 22:24:16 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

// static int		g_i = 0;

void 	disp(t_list *path)
{
	while (path)
	{
		ft_printf ("%s - ", ((t_room *)path->content)->name);
		path = path->next;
	}
	ft_putendl("");
}

void	lem_find_path(t_list *path, t_room *room)
{
	(void)&path;
	t_list	*links;
	t_room	*next_room;
	// static int		i = 0;

	links = room->links;
	while (links)
	{
		next_room = links->content;
		// ft_printf("%s\n", next_room->name);
		if (!next_room->busy)
		{
			next_room->busy = 1;
			ft_lstadd_last(&path, ft_lstptr(next_room));
			if (next_room->position == END - 1)
			{
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));
				next_room->busy = 0;
				ft_lstclr_last(&path);
				return ;
			}
			// if ()
			// ft_printf("%s\n", next_room->name);
			lem_find_path(path, next_room);
			next_room->busy = 0;
			ft_lstclr_last(&path);
		}
		links = links->next;
	}
	// ft_printf("=====\n", next_room->name);
}

int		lem_get_paths(void)
{
	t_room	*room;
	t_list	*path;
	t_list	*links;

	path = NULL;
	room = lem_get_start(g_rooms);
	room->busy = 1;
	links = room->links;
	while (links)
	{
		room = links->content;
		room->busy = 1;
		ft_lstadd_last(&path, ft_lstptr(room));
		lem_find_path(path, room);
		room->busy = 0;
		ft_lstptrdel(&path);
		links = links->next;
	}
	return (ft_lstsortlen(g_paths));
}
