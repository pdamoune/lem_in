/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:17:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/15 19:31:35 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_find_path(t_list *paths, t_list *path, t_room *room)
{
	t_list	*links;
	t_room	*next_room;
	static int i = 0;
	static int shrt_len = INT_MAX;
	// int		len;

	links = room->links;
	while (links)
	{
		next_room = links->content;
		i++;
		if (!next_room->busy)
		{
			next_room->busy = 1;
			ft_lstadd_last(&path, ft_lstptr(next_room));
			if (next_room->position == END - 1)
			{
				ft_lstclr_last(&path);
				shrt_len = ft_lstlen(path);
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));

				next_room->busy = 0;
				i--;
				return (shrt_len);
			}
			shrt_len = lem_find_path(paths, path, next_room);
			next_room->busy = 0;
			ft_lstclr_last(&path);
		}
		links = links->next;
		i--;
	}
	return (shrt_len);
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
	path = NULL;
	links = room->links;
	while (links)
	{
		room = links->content;
		room->busy = 1;
		ft_lstadd_last(&path, ft_lstptr(room));
		lem_find_path(paths, path, room);
		ft_lstptrdel(&path);
		links = links->next;
		// 	path = ft_lstptr(start);
	}
	return (0);
}

void 	ft_lstswap_content(t_list *lst1, t_list *lst2)
{
	t_list	*tmp;

	if (!lst1 || !lst2)
		return ;
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
			ft_lstswap_content(tmp, tmp->next);
			tmp = list;
		}
		else
			tmp = tmp->next;
	}
	return (len);
}



int		lem_solver(void)
{
	t_room	*start;
	t_list	*paths;

	// char	*graph;
	int		len_paths;
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
	len_paths = ft_lstlen(paths);
	// lem_get_not_crossed


	ft_printf("\n======== FIN SOLVER ========\n");
	return (0);
}
