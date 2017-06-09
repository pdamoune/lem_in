/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:00:18 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/09 17:15:51 by pdamoune         ###   ########.fr       */
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

int		lem_get_lines(t_list **data)
{
	t_list	*tmp;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		!*data ? *data = tmp : ft_lstadd_last(*data, tmp);
		i++;
	}
	return (ret + 1);

}

int		lem_is_com(char *line)
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

int		lem_is_room(t_data *data, t_room *room, char *line)
{
	int		len;
	int		x;
	int		y;

	len = ft_strlen(line);
	while (line[--len] == ' ')
		;
	line[++len] = 0;
	while (ft_isdigit(line[--len]))
		;
	if (line[len] != ' ' || !ft_isint(&line[++len]))
		return (0);
	y = ft_atoi(&line[len]);
	line[--len] = 0;
	while (ft_isdigit(line[--len]))
		;
	if (!ft_isint(&line[++len]))
		return (0);
	x = ft_atoi(&line[len]);
	line[--len] = 0;
	room->x = x;
	room->y = y;
	data->map[0] < x ? data->map[0] = x : 0;
	data->map[1] < y ? data->map[1] = y : 0;
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
		{
			line[i] = '-';
			continue ;
		}
		link->room1 = ft_strdup(line);
		link->room2 = &line[i] + 1;
		line[i] = '-';
		return (1);

	}
	(void)&link;
	return (0);
}

int		lem_get_links(t_data *data, t_list *list_datas, t_list *l_rooms, t_list **l_links)
{
	t_list	*tmp;
	t_link	*link;
	char	*ptr;
	t_room	room;
	int 	i;

	i = -1;
	link = ft_memalloc(sizeof(t_link));
	while ((list_datas = list_datas->next))
	{

		ptr = ft_strdup(list_datas->content);
		if ((lem_is_com(ptr)) > 0 || lem_is_room(data, &room, ptr))
			continue ;

		if (!lem_is_link(l_rooms, link, ptr))
		{
			return (0);
		}
		tmp = ft_lstnew(link, sizeof(t_link));
		!*l_links ? *l_links = tmp : ft_lstadd_last(*l_links, tmp);
		link = ft_memalloc(sizeof(t_link));

	}
	return (1);
}

int		lem_get_rooms(t_data *data, t_list *list_data, t_list **list_rooms)
{
	t_list	*tmp;
	t_room	*room;
	t_link	link;
	char	*line;
	int		com;
	int		rooms;

	com = 0;
	rooms = 0;
	room = ft_memalloc(sizeof(t_room));
	while ((list_data = list_data->next))
	{
		if ((com = lem_is_com(list_data->content)))
		{
			if (com > 1)
				room->pos = com;
			continue ;
		}
		if (!lem_is_room(data, room, (line = ft_strdup(list_data->content))))
		{
			ft_strdel(&line);
			if (!lem_is_link(*list_rooms, &link, list_data->content))
			{
				return (0);
			}
			continue ;
		}
		tmp = ft_lstnew(room, sizeof(t_room));
		!*list_rooms ? *list_rooms = tmp : ft_lstadd_last(*list_rooms, tmp);
		room->pos ? (rooms |= (room->pos - 1)) : 0;
		room = ft_memalloc(sizeof(t_room));
	}
	return (rooms);
}

int		lem_get_ants(t_list *data, int *ants)
{
	char	*line;

	line = data->content;
	while (data && lem_is_com(line))
	{
		data = data->next;
		line = data->content;
	}
	if (ft_isint(line) > 0)
	{
		*ants = ft_atoi(line);
		return (1);
	}
	return (0);
}

int		lem_get_graph(t_data *data, t_list *rooms, t_list *links)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	x = data->map[0] + 1;
	y = data->map[1] + 1;
	data->graph = ft_memalloc(sizeof(char *) * y);
	while (++i < y)
		(data->graph[i] = ft_memalloc(x)) && ft_memset(data->graph[i], ' ', x);
	i = 0;
	while (rooms)
	{
		x = ((t_room *)rooms->content)->x;
		y = ((t_room *)rooms->content)->y;
		ft_strncpy(&data->graph[y][x], ((t_room *)rooms->content)->name, 1);
		rooms = rooms->next;

	}
	(void)&rooms;
	(void)&links;
	return (0);
}


int		lem_parsing(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map[0] = 0;
	data->map[1] = 0;
	ft_printf("\n======== PARSING ========\n");
	ft_printf("retour get_lines = %d\n", lem_get_lines(&data->list_data));
	ft_printf("retour get_ants  = %d | ", lem_get_ants(data->list_data, &data->ants));
	ft_printf("ants  = %d\n", data->ants);
	ft_printf("retour get_rooms = %.2b\n", lem_get_rooms(data, data->list_data, &data->list_rooms));
	ft_printf("retour get_links = %d\n", lem_get_links(data, data->list_data, data->list_rooms, &data->list_links));
	lem_get_graph(data, data->list_rooms, data->list_links);
	ft_printf("=========================\n");
	return (1);
}
