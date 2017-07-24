/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:11:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/24 20:34:40 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

// static int		g_i = 0;

static void 	lem_clr_path(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->position != START - 1)
			((t_room *)(path->content))->busy = 0;
		path = path->next;
	}
}

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
			if (next_room->position == END - 1)
				//   && (i <= len || lem_diff_path(g_paths, path)))
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

int		lem_test_paths(t_list *path, t_room *room, t_list *links, int n)
{
	static int	i = 1;
	t_list		*links_tmp;
	t_room		*room_tmp;

	links_tmp = links;
	room_tmp = room;
	if (room->position == START - 1 && n == i - 1)
		lem_display(1, "list", path);
	if (i > n)
		return (0);
	while (links_tmp)
	{
		room_tmp = links_tmp->content;
		if (!room_tmp->busy)
		{
			// ft_printf("%d |%d| - %s - \n", room_tmp->position, i, room_tmp->name);
			room_tmp->busy = 1;
			i++;
			ft_lstadd_last(&path, ft_lstptr(room_tmp));
			lem_test_paths(path, room_tmp, room_tmp->links, n);
			ft_lstclr_last(&path);
			// ft_printf("%s - ", room_tmp->name);
			// ft_printf("\n");
			i--;
			room_tmp->busy = 0;
		// 	room_tmp->busy = 0;
		}
		links_tmp = links_tmp->next;
	}
	// room_tmp->busy = 0;

	// lem_test_paths(path, room, links, n);
	// if (lem_test_paths(path, room, room->links, n))
	// 	return (1);
	return (0);
}

int		lem_get_paths(void)
{
	t_room	*room;
	t_list	*path;

	room = lem_get_end(g_rooms);
	path = ft_lstptr(room);
	g_paths = ft_lstptr(path);
	lem_clr_path(g_rooms);
	room->busy = 1;
	lem_display(1, "rooms");
	lem_test_paths(path, room, room->links, 10);
	room->busy = 1;
	// lem_find_path(path, room);

	return (ft_lstsortlen(g_paths));
}
