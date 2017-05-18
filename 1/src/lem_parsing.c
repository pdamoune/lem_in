/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:00:18 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/18 05:11:40 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void 	ft_del(void *ptr, size_t size)
{
	ft_bzero(ptr, size);
	free(ptr);
}

int 	lem_get_coms(t_list *list, char *line)
{
	if (line[0] == '#')
	{
		if (!ft_strncmp(&line[1], "#start", 6))
		{
			list = list->next;
			lem_get_coms(list, list->content);
			return (START);
		}
		if (!ft_strncmp(&line[1], "#end", 4))
		{
			list = list->next;
			lem_get_coms(list, list->content);
			return (END);
		}
		return (3);
	}
	(void)&list;
	return (0);
}

int		lem_get_coordonnee(char *line, int *len)
{
	int		coordonnee;

	if (!ft_isdigit(line[*len]))
		return (-1);
	while (ft_isdigit(line[*len]))
		(*len)--;
	coordonnee = ft_atoi(&line[*len]);
	while (ft_isspace(line[*len]))
		(*len)--;
	if (line[*len + 1] != ' ')
		return (-1);
	ft_bzero(&line[*len + 1], ft_strlen(&line[*len]));
	return (coordonnee);
}

t_room 	*lem_get_rooms(t_list **rooms, char *line)
{
	t_list	*tmp;
	t_room	*room;
	int		len;

	room = ft_memalloc(sizeof(t_room));
	len = ft_strlen(line) - 1;
	room->y = lem_get_coordonnee(line, &len);
	room->x = lem_get_coordonnee(line, &len);
	room->name = line;
	tmp = ft_lstnew(room, sizeof(t_room));
	!*rooms ? *rooms = tmp : ft_lstadd_last(*rooms, tmp);
	return (room);
}

int 	lem_get_links(t_list **links, t_list *rooms, char *line)
{
	t_link	*link;
	int		i;

	link = ft_memalloc(sizeof(t_link));
	i = 0;
	if (!ft_strchr(line, '-'))
		return (-1);
	while (line[i] && line[i] != '-')
			i++;
	link->room2 = ft_strdup(&line[i + 1]);
	line[i] = 0;
	link->room1 = ft_strdup(line);
	(void)&line;
	(void)&rooms;
	(void)&links;
	return (1);
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
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		!*list ? *list = tmp : ft_lstadd_last(*list, tmp);
		i++;
	}
}

int		lem_parsing(t_list *l_rooms, t_list *l_links, int *nb_ants)
{
	t_list	*list;

	list = NULL;
	l_rooms = NULL;
	lem_get_lines(&list);
	lem_get_rooms(&l_rooms, list->content);
	lem_get_links(&l_links, l_rooms, list->content);
	ft_putnbrel(ft_atoi("-999999999999999999999999999"));
	while (l_rooms)
	{
		ft_putendl(((t_room *)l_rooms->content)->name);
		ft_putnbrel(((t_room *)l_rooms->content)->x);
		ft_putnbrel(((t_room *)l_rooms->content)->y);
		l_rooms = l_rooms->next;
	}
	// (void)&links;
	// (void)&rooms;
	(void)&nb_ants;
	return (0);
}
