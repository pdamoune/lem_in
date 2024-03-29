/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:59:40 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/09 17:07:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static int	cmp_room_number(t_room *room, int *room_number)
{
	if (room->room_number == *room_number)
		return (0);
	return (1);
}

static int	cmp(t_room *room, char *data)
{
	if (!ft_strcmp(room->name, data))
		return (0);
	return (1);
}

void		lem_set_link(t_room *room1, t_room *room2)
{
	if (room1->room_number == room2->room_number)
		return ;
	if (!room1->links)
		room1->links = ft_lstptr(room2);
	else if (!ft_lstfind(room1->links, &room2->room_number, &cmp_room_number))
		ft_lstadd_last(&room1->links, ft_lstptr(room2));
	if (!room2->links)
		room2->links = ft_lstptr(room1);
	else if (!ft_lstfind(room2->links, &room1->room_number, &cmp_room_number))
		ft_lstadd_last(&room2->links, ft_lstptr(room1));
}

int			lem_is_link(char *line)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	i = -1;
	tmp1 = NULL;
	tmp2 = NULL;
	while (line[++i])
	{
		if (line[i] != '-')
			continue ;
		line[i] = 0;
		if (!(tmp1 = ft_lstfind(g_rooms, line, &cmp))
		|| !(tmp2 = ft_lstfind(g_rooms, &line[i + 1], &cmp)))
		{
			line[i] = '-';
			continue ;
		}
		lem_set_link(tmp1->content, tmp2->content);
		break ;
	}
	if (!tmp1 || !tmp2)
		return (0);
	line[i] = '-';
	return (1);
}
