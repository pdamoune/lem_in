/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/13 16:34:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_list	*lem_find_path(t_list *paths, t_list *path, t_room *room)
{
	t_list	*links;
	t_room	*next_room;

	links = room->links;
	while (links)
	{
		next_room = links->content;
		if (!next_room->busy)
		{
			next_room->busy = 1;
			ft_lstadd_last(&path, ft_lstptr(next_room));
			if (next_room->position == END - 1)
			{
				if (!g_paths)
					 g_paths = ft_lstptr((ft_lstdup(path)));
				else
					ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));
				next_room->busy = 0;
				ft_lstclr_last(&path);
				return (path);
			}
			lem_find_path(paths, path, next_room);
			next_room->busy = 0;
			ft_lstclr_last(&path);
		}
		links = links->next;
	}
	return (NULL);
}

// static void 	del(void *room, size_t size)
// {
// 	(void)&room;
// 	(void)&size;
//
// }

int		lem_get_paths(t_list *paths, t_room *room)
{
	t_room	*start;
	t_list	*path;
	t_list	*links;
	// t_list	*patht;


	start = room;
	path = ft_lstptr(room);
	links = room->links;
	while (links)
	{
		room = links->content;
		room->busy = 1;
		ft_lstadd_last(&path, ft_lstptr(room));
		lem_find_path(paths, path, room);
		room->busy = 0;
		ft_lstptrdel(&path);
		if ((links = links->next))
			path = ft_lstptr(start);
	}
	return (0);
}

void 	ft_lstswap(t_list *lst1, t_list *lst2)
{
	t_list	*tmp;

	tmp = lst1->content;
	lst1->content = lst2->content;
	lst2->content = tmp;

}

int		ft_lstsortlen(t_list *list)
{
	// t_list	*path;
	t_list	*tmp;
	int		len;

	tmp = list;
	while (tmp)
	{
		len = ft_lstlen(tmp->content);
		if (tmp->next && ft_lstlen(tmp->next->content) < (size_t)len)
		{
			ft_lstswap(tmp, tmp->next);
			tmp = list;
		}
		else
			tmp = tmp->next;
	}
	return (len);
}

// void 	ft_on_essaye(t_list *all_paths1, t_list *all_paths2)
// {
// 	t_list	*path1;
// 	t_list	*path2;
//
// 	all_paths2 = all_paths1;
// 	while (all_paths1)
// 	{
// 	}
//
//
// }

int		lem_solver(void)
{
	t_room	*start;
	// t_list	*path;
	t_list	*paths;
	t_list	*tmp;
	size_t	lst_len;
	size_t	len;
	char	**graph;
	// long	*graph;
	int		i;
	int		j;


	ft_printf("\n========   SOLVER   ========\n");
	start = lem_get_start(g_rooms);
	i = 0;
	j = 0;
	start->busy = 1;
	lem_get_paths(g_paths, start);
	paths = g_paths;
	ft_lstsortlen(paths);
	lst_len = ft_lstlen(paths);
	len = ft_lstlen(g_rooms);
	ft_putnbrel(lst_len);
	ft_putnbrel(len);
	graph = ft_memalloc(sizeof(char *) * (lst_len + 1));
	// ft_on_essaye(g_paths, paths);
	while (paths)
	{
		graph[i] = ft_memalloc(len + 1);
		tmp = paths->content;
		while (tmp)
		{
			if (((t_room *)tmp->content)->position < 1)
				graph[i][((t_room *)tmp->content)->room_number] = 1;
			tmp = tmp->next;
		}
		paths = paths->next;
		i++;
	}
	// i = 0;
	// j = len;
	// ft_printf("coucou\n");
	//
	// while (graph[i])
	// {
	// 	while (j-- > 0)
	// 		ft_printf("%d", graph[i][j]);
	// 	ft_printf("\n");
	// 	j = len;
	// 	i++;
	// }


	ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
