/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/16 18:15:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>
#include <stdio.h>

static void display(void *content)
{
	static int		i = 0;

	if (!ft_strcmp((char *)content, "start"))
		i = 0;
	ft_printf("%-2d = %s\n", i++, content);
}

static int	cmp(t_room *room, char *data)
{
	return (ft_strcmp(room->name, data));
	return (1);
}

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



t_room	*lem_get_first_path(t_list *rooms, t_list *links, char *start)
{
	(void)&links;
	(void)&start;
	return (rooms->content);
}

int		test(t_list **paths, t_list *rooms, t_list *links)
{
	t_list	*lst_tmp;
	t_room	*tmp;
	char	*name;

	lst_tmp = *paths;
	while (lst_tmp)
	{
		name = ((t_room *)lst_tmp->content)->name;
		if (!(tmp = lem_get_first_path(rooms, links, name)))
		{
			ft_printf("NO END\n");
			return (0);
		}
		if (!tmp->busy)
		{
			ft_printf("name = %s\n", tmp->name);
			if (tmp->pos == END)
			{
				ft_printf("END\n");
			}
			tmp->busy = 1;

			lst_tmp->next = ft_lstptr(tmp);
		}
		lst_tmp = lst_tmp->next;
	}
	return (0);
}

int		lem_try_rooms(t_list **paths, t_list *rooms, t_list *links)
{
	(void)&paths;
	(void)&rooms;
	(void)&links;
	return (1);
}

char	*lem_rooms_cmp(t_link *link, char *name)
{
	if (!ft_memcmp(name, link->room1, ft_strlen(name) + 1))
	{
		return (link->room2);
	}
	if (!ft_memcmp(name, link->room2, ft_strlen(name) + 1))
	{
		return (link->room1);
	}
	(void)&link;
	(void)&name;
	return (NULL);
}

int		lem_try_path(t_list *paths, t_list *rooms, t_list *links)
{
	static t_list	*path = NULL;
	t_room			*tmp_room;
	char			*name;
	char			*next_room;

	name = ft_lstlast(paths)->content;
	while (links)
	{
		if ((next_room = lem_rooms_cmp(links->content, name)))
		{
			tmp_room = ft_lstfind(rooms, next_room, &cmp)->content;
			if (!tmp_room->busy)
			{
				tmp_room->busy = 1;
				ft_lstadd_last(&paths, ft_lstptr(next_room));
				if (tmp_room->pos == END)
					return (1);
				if ((lem_try_path(paths, rooms, links)))
				{
				}
				tmp_room->busy = 0;
				ft_lstclr_last(&paths);
			}
		}
		if ((links = links->next))
			continue ;
		ft_lstforeach(path, &display);
	}
	// if (path)
	// 	ft_lstforeach(path->content, &display);

	(void)&display;
	(void)&links;
	return (0);
}



int		lem_get_paths(t_list **paths, t_list *rooms, t_list *links)
{
	// t_list	*all_paths;
	t_list	*lst_tmp;
	t_room	*tmp;

	tmp = lem_get_start(rooms);
	tmp->busy = 1;
	lst_tmp = ft_lstptr(tmp->name);
	*paths = lst_tmp;
	// ft_lstforeach(lst_tmp, &display);
	lem_try_path(*paths, rooms, links);
	return (1);
	return (test(paths, rooms, links));
}



int		main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	lem_parsing(&data);
	lem_display(&data, data.list_data, data.list_rooms, data.list_links, 0b11);
	lem_get_paths(&data.list_paths, data.list_rooms, data.list_links);
	// while (data.list_paths->content)
	// {
	// 	ft_printf("%s - ", data.list_paths->content);
	// 	data.list_paths = data.list_paths->next;
	// }
	return (0);
}
