/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/31 20:15:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_nb_paths_max(t_list *paths)
{
	t_room	*room;
	int		paths_max;

	paths_max = 0;
	while (paths)
	{
		room = ((t_list *)paths->content)->content;
		if (!room->busy)
		{
			 room->busy = 1;
			 paths_max++;
		}
		paths = paths->next;
	}
	(void)&paths;
	return (paths_max);
}

void 	lem_busy_path(t_list *path)
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

int 	lem_is_busy(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->busy && !((t_room *)(path->content))->position)
			return (1);
		path = path->next;
	}
	return (0);
}

int 	lem_is_possible(t_list *path, int rayon)
{
	t_room	*room;

	while (path)
	{
		room = path->content;
		if (room->busy || room->weight > rayon)
			return (1);
		path = path->next;
	}
	return (0);
}

int		lem_check_path(t_list *paths, t_list *other_path)
{
	int		r1;
	int		r2;
	t_list	*tmp;

	tmp = other_path;
	while (paths)
	{
		r1 = ((t_room *)paths->content)->room_number;
		ft_printf("paths = %d\n", r1);
		while (tmp)
		{
			r2 = ((t_room *)tmp->content)->room_number;
			if (r1 == r2)
				return (0);
			// ft_printf("r1 = %d\n", r1);
			// ft_printf("r2 = %d\n", r2);
			tmp = tmp->next;
		}
		tmp = other_path;
		paths = paths->next;
	}
	return (1);
}


void 	lem_set_weight(t_list *links, t_room *room)
{
	static int	i = 1;

	while (links)
	{
		room = links->content;
		if (room->position < END - 1 && (room->weight > i || !room->busy))
		{
			// ft_printf("name = %s | ", room->name);
			// ft_printf("i = %d\n", i);
			room->busy = 1;
			room->weight = i;
			i++;
			if (room->position < START - 1)
				lem_set_weight(room->links, room);
			i--;
		}
		links = links->next;
	}
}

int 	lem_get_path(t_list *path, t_list *links, t_room *room, int rayon)
{
	static int	len = 1;
	t_list		*links_tmp;
	t_room		*room_tmp;

	if (room->position == END - 1 || len >= rayon)
		return (room->position == END - 1 && len == rayon ? 1 : 0);
	links_tmp = links;
	while (links_tmp)
	{
		room_tmp = links_tmp->content;
		if (room_tmp->weight < rayon - len && !room_tmp->busy && room_tmp->position != START - 1)
		{
			room_tmp->busy = 1;
			len++;
			ft_lstadd_last(&path, ft_lstptr(room_tmp));
			if (lem_get_path(path, room_tmp->links, room_tmp, rayon))
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));
			ft_lstclr_last(&path);
			len--;
			if (room_tmp->position != START - 1)
				room_tmp->busy = 0;
		}
		links_tmp = links_tmp->next;
	}
	return (0);
}

int		lem_try_rayon(t_list **multiple, t_list *paths, int rayon)
{
	if (!rayon)
	{
		// lem_display(1, "multiple");
		return (1);
	}
	while (paths)
	{
		if (!lem_is_busy(paths->content))
		{
			lem_busy_path(paths->content);
			ft_lstadd_last(multiple, ft_lstptr(paths->content));
			lem_display(1, "list", (*multiple)->content);
			if (!lem_try_rayon(multiple, g_paths, --rayon))
			{
				rayon++;
				// ft_lstclr_last(multiple);
			}
			else
			{
				lem_clr_path(paths->content);
				return (1);
			}
		}
		paths = paths->next;
	}
	return (0);
}

int		lem_try_paths(void)
{
	t_room	*room;
	t_list	*path;
	t_list	*multiple;
	// t_list	*links;
	int		rayon = 0;

	room = lem_get_start(g_rooms);
	path = ft_lstptr(room);
	multiple = NULL;
	while (++rayon < 10)
	{
		multiple = NULL;

		lem_get_path(path, room->links, room, rayon);
		// lem_display(1, "paths", path);
		lem_clr_path(g_rooms);
		while (lem_try_rayon(&multiple, g_paths, rayon))
			;
		// if (ft_lstlen(g_multiple_paths) < ft_lstlen(multiple))
		ft_lstadd_last(&g_multiple_paths, ft_lstptr(multiple));
		lem_clr_path(g_rooms);
		// if (ft_lstlen(multiple) == 40)
		// {
		// 	lem_display(1, "multiple", path);
		// 	break ;
		// }
		// lem_display(1, "list", multiple);
		// ft_putnbrel(ft_lstlen(g_paths));
		// lem_display(1, "rooms");

		// lem_try_rayon(&multiple, g_paths, rayon);
		// ft_lstadd_last(&g_multiple_paths, ft_lstptr(multiple));
	}
	lem_display(1, "multiple", path);
	return (1);
}

int		lem_solver(void)
{
	// int		len;
	t_room		*end;

	ft_printf("\n========   SOLVER   ========\n");
	end = lem_get_end(g_rooms);
	end->busy = 1;
	end->weight = -1;
	lem_set_weight(end->links, end);
	lem_clr_path(g_rooms);
	lem_try_paths();
	// // lem_display(1, "rooms");
	// end->weight = 0;
	// end->busy = 0;
	// // lem_display(1, "rooms");
	// lem_display(1, "rooms");
	// lem_get_paths();
	// lem_display(1, "paths");


	// ft_printf("nbre paths = %d\n", lem_nb_paths_max(g_paths));
	// ft_printf("nb paths max = %d\n", ft_lstlen(g_paths));
	// lem_multiple_paths(g_paths, lem_nb_paths_max(g_paths));
	// lem_display(1, "list", g_rooms);
	ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
