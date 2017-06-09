/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 00:06:28 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/10 00:21:23 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static int		cmp(t_room *room, char *data)
{
	if (!ft_memcmp(room->name, data, ft_strlen(room->name) + 1))
		return (0);
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
		if (!ft_lstfind(l_rooms, line, &cmp)
		|| !ft_lstfind(l_rooms, &line[i + 1], &cmp))
		{
			line[i] = '-';
			continue ;
		}
		link->room1 = ft_strdup(line);
		link->room2 = &line[i] + 1;
		line[i] = '-';
		return (1);
	}
	return (0);
}
