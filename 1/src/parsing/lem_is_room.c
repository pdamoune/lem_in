/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 22:57:27 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/09 23:07:57 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

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
