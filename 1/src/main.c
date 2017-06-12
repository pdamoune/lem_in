/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/12 19:48:45 by pdamoune         ###   ########.fr       */
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
		tmp = tmp->next;
	}
	return (NULL);
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

void 	dresult(t_list *list)
{
	while (list)
	{
		ft_printf("%s - ", list->content);
		list = list->next;
	}
	ft_printf("\n");
}

t_list		*lem_try_path(t_list **paths, t_list *rooms, t_list *links)
{
	static t_list	*all_paths = NULL;
	t_room	*tmp_room;
	t_list	*tmp_link;
	char	*name;
	char	*next_room;
	// static int i = 0;

	name = (ft_lstlast(*paths))->content;
	tmp_link = links;
	// ft_printf("%d = debut\n", i++);
	while (tmp_link)
	{
		// ft_printf("%d 	= while\n", i++);
		// ft_putendl(name);
		if ((next_room = lem_rooms_cmp(tmp_link->content, name)))
		{
			// ft_printf("%d 		= premier if\n", i++);

			tmp_room = ft_lstfind(rooms, next_room, &cmp)->content;
			if (!tmp_room->busy)
			{
				// ft_printf("%d 			= deuxieme if\n", i++);

				tmp_room->busy = 1;
				ft_lstadd_last(paths, ft_lstptr(next_room));
				if (tmp_room->pos == 3)
				{
					// ft_printf("%d 				= troisieme if\n", i++);
					return (*paths);
				}
				if (lem_try_path(paths, rooms, links))
				{
					// ft_printf("%d 				= quatrieme if\n", i++);
					if (!all_paths)
					{
						all_paths = ft_lstptr(*paths);

					}
					else
						ft_lstadd_last(&all_paths, ft_lstptr(*paths));
				}
				dresult(*paths);
				
				tmp_room->busy = 0;
				ft_lstclr_last(paths);
			}
			// ft_printf("%d 			= fin deuxieme if\n", i++);
			if ((tmp_link = tmp_link->next))
				continue ;
		}
		// ft_printf("%d 		= fin premier if\n", i++);

		if (tmp_link && (tmp_link = tmp_link->next))
			continue ;

	}
	// ft_printf("%d 			= fin while\n", i++);



	(void)&paths;
	(void)&rooms;
	(void)&links;
	return (all_paths);

}

int		lem_get_paths(t_list **paths, t_list *rooms, t_list *links)
{
	t_list	*all_paths;
	t_list	*lst_tmp;
	t_room	*tmp;

	tmp = lem_get_start(rooms);
	tmp->busy = 1;
	lst_tmp = ft_lstptr(tmp->name);
	*paths = lst_tmp;
	all_paths = lem_try_path(paths, rooms, links);

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
