/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_possible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:07:53 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/02 15:08:23 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int 	lem_is_possible(t_list *path, int rayon)
{
	t_room	*room;

	while (path)
	{
		room = path->content;
		if (room->busy || room->weight > rayon)
			return (1);
		path = path->next;
	}
	return (0);
}
