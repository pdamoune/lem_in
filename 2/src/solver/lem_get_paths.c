/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:11:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/27 19:27:41 by pdamoune         ###   ########.fr       */
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
	// lem_display(1, "list", path);
	while (path)
	{
		if (((t_room *)(path->content))->busy && !((t_room *)(path->content))->position)
			return (1);
		path = path->next;
	}
	// ft_printf("%s\n", ((t_room *)(path->content))->name);
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
			// if (!next_room->position)
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

			room_tmp->busy = 1;
			i++;
			ft_lstadd_last(&path, ft_lstptr(room_tmp));
			if (lem_test_paths(path, room_tmp, room_tmp->links, n))
			{
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));

			}

			ft_lstclr_last(&path);
			i--;
			room_tmp->busy = 0;
		}
		links_tmp = links_tmp->next;
	}
	return (0);
}

int		lem_get_multiple_paths(t_list **multiple, t_list *path, size_t len)
{
	if ( !len)
	{
		lem_clr_path(g_rooms);
		return (1);
	}
	while (path)
	{
		if (!lem_is_busy(path->content))
		{
			lem_busy_path(path->content);
			ft_lstadd_last(multiple, ft_lstptr(path->content));
			if (!lem_get_multiple_paths(multiple, g_paths, --len))
			{
				len++;
				ft_lstclr_last(multiple);
			}
			else
				return (1);
		}
		path = path->next;
	}
	ft_lstclr_last(multiple);
	return (0);
}

int		lem_check_multipaths(t_list *paths, t_list *links, int ants, int i)
{
	(void)&paths;
	(void)&ants;
	(void)&links;
	(void)&i;
	(void)&lem_is_busy;
	(void)&lem_busy_path;
	// static int	nb_paths = 0;
	static int		j = 0;
	t_list		*multiple;

	multiple = NULL;
	// ft_printf("check = %d\n",
	lem_get_multiple_paths(&multiple, g_paths, i);
	lem_clr_path(g_rooms);
	if (ft_lstlen(multiple))
	{
		j++;
		ft_lstadd_last(&g_multiple_paths, ft_lstptr(multiple));
	}
	ft_putnbrel(j);
	// lem_display(1, "paths");
	// lem_display(1, "multiple");
	return (1);

}


int		lem_get_paths(void)
{
	t_room	*room;
	t_list	*path;
	size_t i = -1;
	int 	len;

	room = lem_get_start(g_rooms);
	path = ft_lstptr(room);
	lem_clr_path(g_rooms);
	len = ft_lstlen(room->links);
	while (ft_lstlen(g_multiple_paths) < (size_t)len)
	{
		++i;
		lem_test_paths(path, room, room->links, i);
		// lem_display(1, "paths");
		if (!g_paths)
			continue;
		while (!g_multiple_paths || ft_lstlen(((t_list *)(ft_lstlast(ft_lstlast(g_multiple_paths)->content))->content)) < i)
		{
			if (ft_lstlen(g_multiple_paths) >= (size_t)len)
				break ;
			lem_check_multipaths(g_paths, room->links, g_ants, ft_lstlen(g_multiple_paths) + 1);

			// lem_display(1, "multiple");

			// ft_printf("len = %d\n", ft_lstlen(((t_list *)(ft_lstlast(ft_lstlast(g_multiple_paths)->content))->content)));
			// ft_printf("i = %d\n", i);
			// if (ft_lstlen(g_multiple_paths) == 7)
			// 	exit(0);
		}
			// lem_check_multipaths(g_paths, room->links, g_ants, ft_lstlen(g_multiple_paths) + 1);
		// ft_printf("len = %d\n",
		// ft_lstlen(ft_lstlast(((t_list *)ft_lstlast(g_multiple_paths)->content)->content)));
		// ft_printf("i = %d\n", i);
		// if (i > 19)
		{
			// exit (0);
		}
	}
	// lem_display(1, "list", ((t_list *)(ft_lstlast(ft_lstlast(g_multiple_paths)->content))->content));
	return (ft_lstsortlen(g_paths));
}
