/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:43:11 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/24 17:47:52 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_is_room(t_room *room, char *line)
{
	static int	numero_rooms = 0;
	int			len;

	len = ft_strlen(line);
	while (len && ft_isdigit(line[--len]))
		;
	if (line[len] != ' ' || !ft_isint(&line[len + 1]))
		return (0);
	room->coor[1] = ft_atoi(&line[len + 1]);
	while (len && ft_isdigit(line[--len]))
		;
	if (!len || !ft_isint(&line[++len]))
		return (0);
	room->coor[0] = ft_atoi(&line[len]);
	room->name = ft_strsub(line, 0, len - 1);
	room->room_number = ++numero_rooms;
	room->weight = INT_MAX;
	return (1);
}
