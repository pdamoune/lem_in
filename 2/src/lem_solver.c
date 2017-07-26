/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/25 13:46:13 by philippedamoune  ###   ########.fr       */
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
		if (((t_room *)(path->content))->busy)
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


int		lem_get_shorter_path(t_list *paths, int nb)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;


(void)&nb;
	i = 1;
	tmp = NULL;
	tmp2 = NULL;
	while (paths)
	{
		tmp = g_paths;
		while (tmp)
		{
			if (!lem_is_busy(tmp->content))
			{
				if (nb >= i++)
				{
					lem_busy_path(tmp->content);
					tmp2 = tmp->content;
					while (tmp2)
					{
						ft_printf("%s - ", ((t_room *)tmp2->content)->name);
						tmp2 = tmp2->next;
					}
					ft_printf("\n");

					continue ;
				}
				else
					return (0);
			}
			tmp = tmp->next;
		}
		lem_clr_path(g_rooms);
		paths = paths->next;
	}
	return (0);
}

int		lem_multiple_paths(t_list *paths, int paths_max)
{
	int i = 0;

	ft_printf("paths_max = %d\n", paths_max);
	while (i++ < paths_max)
	{
		lem_clr_path(g_rooms);
		ft_printf("paths numero  = %d\n", i);
		lem_get_shorter_path(paths, i);
		// lem_display(1, "multiple", g_multiple_paths);
	}
	(void)&paths;
	(void)&paths_max;
	return (0);
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
			lem_set_weight(room->links, room);
			i--;
		}
		links = links->next;
	}
}

int		lem_solver(void)
{
	// int		len;
	t_room		*end;

	ft_printf("\n========   SOLVER   ========\n");
	end = lem_get_end(g_rooms);
	end->busy = 1;
	lem_set_weight(end->links, end);
	// lem_display(1, "rooms");
	end->weight = 0;
	end->busy = 0;
	// lem_display(1, "rooms");
	lem_get_paths();


	// ft_printf("nbre paths = %d\n", lem_nb_paths_max(g_paths));
	// ft_printf("nb paths max = %d\n", ft_lstlen(g_paths));
	// lem_multiple_paths(g_paths, lem_nb_paths_max(g_paths));
	// lem_display(1, "list", g_rooms);
	ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
