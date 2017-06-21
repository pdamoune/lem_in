/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 14:58:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>
#include <stdio.h>

static void display_paths(void *content)
{
	static int		i = 0;

	if (!ft_strcmp(((t_list *)content)->content, "start"))
		i = 0;
	while (content)
	{
		ft_printf("%-2d = %s\n", i++, ((t_list *)content)->content);
		content = ((t_list *)content)->next;
	}
	ft_printf("=====\n");
}

static void display(void *content)
{
	static int		i = 0;

	if (!ft_strcmp(content, "1"))
		i = 0;
	ft_printf("%s - ", content);
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
		if (((t_room *)rooms->content)->pos == END)
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

int		lem_try_path(t_list **all_paths, t_list *path, t_list *rooms, t_list *links)
{
	t_room			*tmp_room;
	t_list			*link_tmp;
	t_list			*room_tmp;
	char			*name;
	char			*next_room;
	static size_t	len = INT_MAX;
	// int				len2;

	link_tmp = links;
	room_tmp = rooms;
	name = ft_lstfirst(path)->content;
	// ft_printf("%s - %s\n", ((t_link *)link_tmp->content)->room1, ((t_link *)link_tmp->content)->room2);
	while (link_tmp)
	{
		// ft_printf("%s - %s\n", ((t_link *)link_tmp->content)->room1, ((t_link *)link_tmp->content)->room2);

		if ((next_room = lem_rooms_cmp(link_tmp->content, name)))
		{
			tmp_room = ft_lstfind(rooms, next_room, &cmp)->content;

			if (ft_lstlen(path) < len)
				if (!tmp_room->busy)
				{
					tmp_room->busy = 1;
					ft_lstadd(&path, ft_lstptr(next_room));
					if (tmp_room->pos == START)
					{
						ft_lstforeach(path, &display);
						ft_putendl("");
						len = ft_lstlen(path);
						if (!*all_paths)
							*all_paths = ft_lstptr(ft_lstcpy(path));
						else
							ft_lstadd(all_paths, ft_lstptr(ft_lstcpy(path)));
					}
					lem_try_path(all_paths, path, rooms, links);


					tmp_room->busy = 0;
					ft_lstclr_first(&path);
					// ft_putendl(path->content);
					// ft_putendl("");
					// ft_putstr("{");
					// ft_lstforeach(path, &display);
					// ft_putendl("}");
				}
		}
		if ((link_tmp = link_tmp->next))
			continue ;
	}
	// if (path)

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
	// ft_lstforeach(lst_tmp, &display);
	lem_try_path(paths, lst_tmp, rooms, links);
	// ft_lstforeach(*paths, &display_paths);
(void)&display_paths;

	return (1);
	return (test(paths, rooms, links));
}



int		main(void)
{
	t_data	*data;

	data = lem_data();
	lem_parsing(data);
	lem_display(data, data->list_data, data->list_rooms, data->list_links, 0b11);
	lem_get_paths(&data->list_paths, data->list_rooms, data->list_links);
	// while (data.list_paths->content)
	// {
	// 	ft_printf("%s - ", data.list_paths->content);
	// 	data.list_paths = data.list_paths->next;
	// }
	return (0);
}
