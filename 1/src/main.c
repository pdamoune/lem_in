/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/10 01:02:48 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>
#include <stdio.h>

t_room	*lem_get_start(t_list *rooms)
{
	t_room	*tmp;

	tmp = NULL;
	while (rooms)
	{
		if (((t_room *)rooms->content)->pos == START)
		{
			tmp = rooms->content;
			return (tmp);
		}
		rooms = rooms->next;
	}
	return (tmp);
}

static int	cmp(t_room *room, char *data)
{
	return (ft_strcmp(room->name, data));
	return (1);
}

t_room	*lem_get_first_path(t_list *rooms, t_list *links, char *start)
{
	t_list	*tmp;
	t_list	*path;
	t_room	*room;
	char	*room1;
	char	*room2;

	tmp = links;
	path = NULL;
	while (tmp)
	{
		room1 = ((t_link *)tmp->content)->room1;
		room2 = ((t_link *)tmp->content)->room2;
		if (!ft_strcmp(start, room1))
		{
			room = ft_lstfind(rooms, room2, &cmp)->content;
			if (!room->busy)
				return (room);
			// ft_printf("lst->room = %s\n\n", ((t_room *)path->content)->name);
		}
		if (!ft_strcmp(start, room2))
		{
			room = ft_lstfind(rooms, room1, &cmp)->content;
			if (!room->busy)
				return (room);
		}
		if (!tmp->next)
		{

		}
		tmp = tmp->next;
	}

	return (NULL);
}

int		lem_get_paths(t_list *paths, t_list *rooms, t_list *links)
{
	t_list	*lst_tmp;
	t_room	*tmp;
	char	*name;

	tmp = lem_get_start(rooms);
	tmp->busy = 1;
	lst_tmp = ft_lstptr(tmp);
	paths = lst_tmp;
	while (paths)
	{
		name = ((t_room *)paths->content)->name;
		if (!(tmp = lem_get_first_path(rooms, links, name)))
		{
			exit (0);
		}
		if (!tmp->busy)
		{
			ft_printf("name = %s\n", tmp->name);
			if (tmp->pos == END)
			{
				ft_printf("END\n");
			}
			tmp->busy = 1;
			lst_tmp = ft_lstptr(tmp);
			paths->next = lst_tmp;
		}
		paths = paths->next;
	}

	return (0);
}

int		main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	lem_parsing(&data);
	lem_display(&data, data.list_data, data.list_rooms, data.list_links, 0b11);
	lem_get_paths(data.list_paths, data.list_rooms, data.list_links);
	return (0);
}
