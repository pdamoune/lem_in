/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/20 23:02:26 by pdamoune         ###   ########.fr       */
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

void 	lem_clr_path(t_list *path)
{
	while (path)
	{
		((t_room *)(path->content))->busy = 0;
		path = path->next;
	}
}

int 	lem_check_busy_room(t_list *path)
{
	while (path)
	{
		if (!((t_room *)(path->content))->busy)
			return (0);
		path = path->next;
	}
	return (1);
}

int		lem_get_shorter_path(t_list *paths, int nb)
{
	static int	i = 0;
	t_list		*tmp;

	tmp = paths;
	lem_busy_path(paths->content);
	while (paths && i < nb)
	{
		if (++i == nb)
		{
			ft_lstadd_last(&g_multiple_paths, paths->content);
			lem_clr_path(paths->content);
			break ;
		}
		if (lem_check_busy_room(tmp->content))
		{
			// exit (0);
		}
		paths = paths->next;
	}
	return (0);
}

int		lem_multiple_paths(t_list *paths, int paths_max)
{
	int i = 0;

	// ft_putnbrel(paths_max);
	while (i++ < paths_max)
	{
		lem_get_shorter_path(paths, i);
	}




	(void)&paths;
	(void)&paths_max;
	return (0);
}

int		lem_solver(void)
{
	// int		len;

	ft_printf("\n========   SOLVER   ========\n");
	lem_get_paths();
	// ft_printf("nbre paths = %d\n", lem_nb_paths_max(g_paths));
	// ft_printf("nb paths max = %d\n", ft_lstlen(g_paths));
	lem_multiple_paths(g_paths, lem_nb_paths_max(g_paths));

	ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
