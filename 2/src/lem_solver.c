/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/01 14:56:27 by pdamoune         ###   ########.fr       */
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
			tmp = tmp->next;
		}
		tmp = other_path;
		paths = paths->next;
	}
	return (1);
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
			{
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));
			}
			ft_lstclr_last(&path);
			len--;
			if (room_tmp->position != START - 1)
				room_tmp->busy = 0;
		}
		links_tmp = links_tmp->next;
	}
	// if (len == 1)
	// {
	// 	rayon++;
	// 	lem_get_path(path, links, room, rayon);
	// }
	return (0);
}

int		lem_len_multiple(t_list *multiple)
{
	int		len;

	len = 0;
	while (multiple)
	{
		len += ft_lstlen(multiple->content);
		multiple = multiple->next;
	}
	return (len);
}

int		lem_try_rayon(t_list **multiple, t_list *paths, int rayon)
{
	if (!rayon)
	{
		// if (lem_len_multiple(multiple) && lem_len_multiple(multiple))
		return (1);

	}
	while (paths)
	{
		if (!lem_is_busy(paths->content))
		{
			lem_busy_path(paths->content);
			ft_lstadd_last(multiple, ft_lstptr(paths->content));
			if (lem_try_rayon(multiple, g_paths, --rayon))
			{
				lem_clr_path(paths->content);
				return (1);
			}
			rayon++;
		}
		paths = paths->next;
	}
	return (0);
}

// int		lem_get_multiple_paths(t_list **multiple, t_list *links, t_list *paths, int rayon)
// {
// 	while (links)
// 	{
// 		lem_try_rayon(multiple, g_paths, rayon);
// 	}
// 	return (1);
// }

int		lem_get_paths(void)
{
	t_room	*room;
	t_list	*path;
	t_list	*multiple;
	// t_list	*tmp;
	int		rayon = 0;

	room = lem_get_start(g_rooms);
	path = ft_lstptr(room);
	multiple = NULL;
	while (++rayon < 7)
	{
		lem_get_path(path, room->links, room, rayon);
		if (!g_paths)
			continue ;
		// while (tmp)
		// {
		// 	tmp = tmp->next;
		// }
		// lem_clr_path(g_rooms);
		multiple = NULL;
		// lem_get_multiple_paths(&multiple, room->links, g_paths, rayon);
		lem_try_rayon(&multiple, g_paths, rayon);
		lem_display(1, "multiple");
		// tmp = multiple;

		ft_lstadd_last(&g_multiple_paths, ft_lstptr(multiple));
		lem_clr_path(g_rooms);
	}
	// lem_display(1, "multiple");

	return (1);
}

int		lem_solver(void)
{
	// int		len;

	ft_printf("\n========   SOLVER   ========\n");
	lem_set_weight();
	lem_clr_path(g_rooms);
	lem_get_paths();
	ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
