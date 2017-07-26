/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:11:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/25 21:22:32 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

// static int		g_i = 0;

static void 	lem_busy_path(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->position != END - 1)
			((t_room *)(path->content))->busy = 1;
		path = path->next;
	}
}

static void 	lem_clr_path(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->position != START - 1)
			((t_room *)(path->content))->busy = 0;
		path = path->next;
	}
}

static int 	lem_is_busy(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->busy)
			return (1);
		path = path->next;
	}
	return (0);
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
	if (room->position == END - 1 && i == n)
		return (1);
	if (i > n)
		return (0);
	while (links_tmp)
	{
		room_tmp = links_tmp->content;
		if (!room_tmp->busy && room_tmp->position != START - 1)
		{

			// ft_printf("%d |%d| - %s - \n", room_tmp->position, i, room_tmp->name);
			room_tmp->busy = 1;
			i++;
			ft_lstadd_last(&path, ft_lstptr(room_tmp));
			if (lem_test_paths(path, room_tmp, room_tmp->links, n))
			{
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));
				// ret = 0;
			}

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

int		lem_multiple(t_list *paths, size_t len)
{
	t_list	*tmp;
	t_list	*tmp2;
	// t_list	*paths_tmp;
	int		j;

	j = len;
	while (paths)
	{
		if (len == ft_lstlen(g_multiple_paths))
		{
			return (1);
		}
		while (j--)
		{
			tmp = paths->content;
			tmp2 = ft_lstptr(tmp);
			if (!j)
			{
				ft_lstadd_last(&tmp2, tmp);
				return (1);
			}
			if (lem_multiple(g_paths, len))
			{
				ft_lstadd_last(&g_multiple_paths, tmp2);
				return (1);
			}
		}
	}
	return (0);
}

int		lem_check_multipaths(t_list *paths, t_list *links, int ants, int i)
{
	(void)&paths;
	(void)&ants;
	(void)&links;
	(void)&lem_is_busy;
	(void)&lem_busy_path;
	// t_list	*path;
	static int	j = 0;
	int		len;

	while (j < i)
		j++;
	len = ft_lstlen(ft_lstlast(paths)->content);
	ft_printf("ants = %d\n", ants);
	ft_printf("len  = %d\n", len);
	ft_printf("i    = %d\n", i);
	ft_printf("j    = %d\n", j);
	return (1);

}


int		lem_get_paths(void)
{
	t_room	*room;
	t_list	*path;
	int i = 0;

	room = lem_get_start(g_rooms);
	path = ft_lstptr(room);
	// g_paths = ft_lstptr(path);
	lem_clr_path(g_rooms);
	while (ft_lstlen(ft_lstlast(g_paths)) < 3)
	{
		lem_test_paths(path, room, room->links, i);
		i++;
		if (!g_paths)
			continue;
		if (lem_check_multipaths(g_paths, room->links, g_ants, i - 1))
		{
			ft_printf("\n");
		}
			// lem_display(1, "paths");
		// lem_display(2, "rooms", "paths");

			// break ;
			// exit (0);

	}
	// lem_display(2, "rooms", "paths");
	// lem_find_path(path, room);

	return (ft_lstsortlen(g_paths));
}
