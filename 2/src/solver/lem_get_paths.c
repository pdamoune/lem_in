/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:11:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/24 17:09:41 by pdamoune         ###   ########.fr       */
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

int		lem_diff_path(t_list *paths, t_list *path)
{
	int		 r1;
	int		 r2;

	r2 = ((t_room *)path->content)->room_number;
	while (paths)
	{
		r1 = ((t_room *)((t_list *)paths->content)->content)->room_number;
		if (r1 == r2)
			return (0);
		paths = paths->next;
	}
	return (1);
}

int		lem_find_path(t_list *path, t_room *room)
{
	(void)&path;
	t_list	*links;
	t_room	*next_room;
	static int		i = 1;
	static int		len = INT_MAX;

	links = room->links;
	while (links)
	{
		i++;
		next_room = links->content;
		// ft_printf("%s\n", next_room->name);
		if (!next_room->busy)
		{
			// if (lem_diff_path(g_paths, path))
			// 	i = 1;
			next_room->busy = 1;
			ft_lstadd_last(&path, ft_lstptr(next_room));
			if (next_room->position == END - 1  && (i <= len || lem_diff_path(g_paths, path)))
			{
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));
				// lem_display(1, "list", path);
				len = ft_lstlen(path);
				// ft_printf("i = %d len = %d\n", i, len);
				// ft_putendl("");
				next_room->busy = 0;
				ft_lstclr_last(&path);
				i--;
				return (len);

			}
			// if ()
			// ft_printf("%s\n", next_room->name);
			len = lem_find_path(path, next_room);
			next_room->busy = 0;
			ft_lstclr_last(&path);
		}
		i--;
		links = links->next;
	}
	return (len);
	// ft_printf("=====\n", next_room->name);
}

int		lem_get_paths(void)
{
	t_room	*room;
	t_list	*path;
	t_list	*links;
	int		i;

	path = NULL;
	room = lem_get_start(g_rooms);
	links = room->links;
	i = 1;
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
