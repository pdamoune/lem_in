/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 00:06:28 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/09 18:59:56 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static int		cmp(t_room *room, char *data)
{
	if (!ft_strcmp(room->name, data))
		return (0);
	return (1);
}

static int		cmp_str(char *room, char *data)
{
	if (!ft_strcmp(room, data))
		return (0);
	return (1);
}

int		lem_is_link(t_list *l_rooms, t_link *link, char *line)
{
	int		i;
	t_room	*room1;
	t_room	*room2;
	t_list	*r1;
	t_list	*r2;



	i = -1;
	while (line[++i])
	{
		if (line[i] != '-')
			continue ;
		line[i] = 0;
		ft_printf("%s\n", line);
		if (!(r1 = ft_lstfind(l_rooms, line, &cmp))
		|| !(r2 = ft_lstfind(l_rooms, &line[i + 1], &cmp)))
		{
			line[i] = '-';
			continue ;
		}

		// ((t_room *)room2->content)->name)
		// ((t_room *)room1->content)->links);
		// ft_printf("----------\n");
		// ft_printf("----------\n");
		link->room1 = ft_strdup(line);
		link->room2 = &line[i] + 1;
		if (r1 && r2)
		{
			room1 = r1->content;
			room2 = r2->content;
		!room1->links ? room1->links = ft_lstptr(link->room2) : 0;
		!room2->links ? room2->links = ft_lstptr(link->room1) : 0;
		if (!ft_lstfind(room1->links, link->room2, &cmp_str))
			ft_lstadd_last(&room1->links, ft_lstptr(link->room2));
		if (!ft_lstfind(room2->links, link->room1, &cmp_str))
			ft_lstadd_last(&room2->links, ft_lstptr(link->room1));
		}
		line[i] = '-';
		return (1);
	}
	// ft_printf("%s\n", line);
	return (0);
}
