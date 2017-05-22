/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:00:18 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/22 23:00:09 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int		cmp(t_room *room, char *data)
{
	if (!ft_memcmp(room->name, data, ft_strlen(room->name) + 1))
		return (0);

	(void)&room;
	(void)&data;
	return (1);
}

int		lem_iscom(char *line)
{

	if (!line)
		return (-1);
	if (!ft_strncmp(line, "##end", 6))
		return (END);
	if (!ft_strncmp(line, "##start", 8))
		return (START);
	if (line[0] == '#')
		return (COM);
	return (NOT_COM);
}

int		lem_is_room(t_room *room, char *line)
{
	int		len;

	len = ft_strlen(line);
	while (line[--len] == ' ')
		;
	line[++len] = 0;
	while (ft_isdigit(line[--len]))
		;
	if (line[len] != ' ' || !ft_isint(&line[++len]))
		return (0);
	room->y = ft_atoi(&line[len]);
	line[--len] = 0;
	while (ft_isdigit(line[--len]))
		;
	if (!ft_isint(&line[++len]))
		return (0);
	room->x = ft_atoi(&line[len]);
	line[--len] = 0;
	room->name = line;
	return (1);
}

int		lem_is_link(t_list *l_rooms, t_link *link, char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '-')
			continue ;
		line[i] = 0;
		if (!ft_lstfind(l_rooms, line, &cmp) || !ft_lstfind(l_rooms, &line[i + 1], &cmp))
			continue ;
		link->room1 = line;
		link->room2 = &line[i] + 1;
		return (1);

	}
	(void)&link;
	return (0);
}

int		lem_get_links(t_list **l_links, t_list *data, t_list *l_rooms)
{
	t_list	*tmp;
	t_link	*link;
	char	*ptr;
	t_room	room;
	int 	i;

	i = -1;
	link = ft_memalloc(sizeof(t_link));
	while ((data = data->next))
	{
		ptr = ft_strdup(data->content);
		if ((lem_iscom(ptr)) > 0 || lem_is_room(&room, ptr))
			continue ;
		if (!lem_is_link(l_rooms, link, ptr))
			return (0);
		tmp = ft_lstnew(link, sizeof(t_link));
		!*l_links ? *l_links = tmp : ft_lstadd_last(*l_links, tmp);
		link = ft_memalloc(sizeof(t_link));

	}
	return (1);
}

int		lem_get_rooms(t_list *data, t_list **l_rooms)
{
	t_list	*tmp;
	t_room	*room;
	char	*line;
	int		com;
	int		rooms;

	com = 0;
	rooms = 0;
	room = ft_memalloc(sizeof(t_room));
	while ((data = data->next))
	{
		if ((com = lem_iscom(data->content)))
		{
			if (com > 1)
				room->pos = com;
			continue ;
		}
		if (!lem_is_room(room, (line = ft_strdup(data->content))))
		{
			ft_strdel(&line);
			continue ;
		}
		// ft_printf("room = %s\n===========\n", room->name);
		tmp = ft_lstnew(room, sizeof(t_room));
		!*l_rooms ? *l_rooms = tmp : ft_lstadd_last(*l_rooms, tmp);
		room->pos ? (rooms |= (room->pos - 1)) : 0;
		room = ft_memalloc(sizeof(t_room));
	}
	return (rooms);
}

int		lem_get_ants(t_list *data)
{
	char	*line;
	int		ret;

	line = data->content;
	while (data && lem_iscom(line))
	{
		data = data->next;
		line = data->content;
	}
	if (ft_isint(line) > 0)
	{
		ret = ft_atoi(line);
		return (ret);
	}
	errno |= BAD_ANTS;
	return (-1);
}

void	lem_get_lines(t_list **list)
{
	t_list	*tmp;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		tmp = ft_lstnew(line, sizeof(char *));
		!*list ? *list = tmp : ft_lstadd_last(*list, tmp);
		i++;
	}

}

void 	lem_display(t_list *rooms, t_list *links)
{
	t_room	*room;
	t_link	*link;

	while (rooms)
	{
		room = rooms->content;
		ft_printf("name = |%s|\n", room->name);
		ft_printf("pos  = |%d|\n", room->pos);
		ft_printf("-------------\n");
		rooms = rooms->next;
	}
	while (links)
	{
		link = links->content;
		ft_printf("room1 = |%s|\n", link->room1);
		ft_printf("room2 = |%s|\n", link->room2);
		ft_printf("===============\n");
		links = links->next;
	}
}

int		lem_parsing(t_data *data, t_list *l_rooms, t_list *l_links, int *ants)
{
	t_list	*data1;
	// t_room 	*room;

	data1 = NULL;
	(void)&data;
	lem_get_lines(&data1);
	*ants = lem_get_ants(data1);
	lem_get_rooms(data1, &l_rooms);
	lem_get_links(&l_links, data1, l_rooms);
	lem_display(l_rooms, l_links);
	// while (l_rooms)
	// {
	// 	room = l_rooms->content;
	// 	ft_printf("name = |%s|\n", room->name);
	// 	ft_printf("pos  = |%d|\n", room->pos);
	// 	ft_printf("-------------\n");
	// 	l_rooms = l_rooms->next;
	// }

	(void)&l_links;
	(void)&l_rooms;
	return (-1);
}
