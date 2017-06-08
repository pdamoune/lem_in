/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/30 16:57:17 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>
#include <stdio.h>

t_list	*lem_get_starts(t_list *rooms)
{
	t_list	*starts;
	t_list	*tmp;
	char	*name;

	starts = NULL;
	while (rooms)
	{
		if (((t_room *)rooms->content)->pos == START)
		{
			name = ((t_room *)rooms->content)->name;

			tmp = ft_lstnew(name, ft_strlen(name) + 1);
			!starts ? starts = tmp : ft_lstadd_last(starts, tmp);
		}
		rooms = rooms->next;
	}
	return (starts);
}

int		lem_get_shorter_path(t_list *rooms, t_list *links, char *start)
{
	t_list	*tmp;
	char	*room1;
	char	*room2;

	tmp = links;
	while (tmp)
	{
		room1 = ((t_link *)tmp->content)->room1;
		room2 = ((t_link *)tmp->content)->room2;

		if (!ft_strcmp(start, room1))
			ft_putendl(room2);
		// if (!ft_strcmp(room2, start))
		// 	ft_putendl(room2);
		tmp = tmp->next;
	}
	(void)&rooms;
	(void)&links;
	return (1);
}

int		lem_get_paths(t_list *paths, t_list *rooms, t_list *links)
{
	t_list	*starts;

	starts = lem_get_starts(rooms);
	lem_get_shorter_path(rooms, links, starts->content);
	while (starts)
	{
		ft_printf("starts = %s\n", starts->content);
		starts = starts->next;
	}


	(void)&links;
	(void)&paths;
	// rooms = ft_lstlen(rooms);
	return (0);
}

int		main(void)
{
	t_data	data;

	if (lem_parsing(&data) == -1)
		return (-1);
	lem_get_paths(data.list_paths, data.list_rooms, data.list_links);
	lem_display(&data, data.list_data, data.list_rooms, data.list_links, 0b11);
	return (0);
}
