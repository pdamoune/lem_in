/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 03:20:18 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 17:36:29 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

t_room		*lem_get_start(t_list *rooms)
{
	while (rooms && ((t_room *)rooms->content)->position != START - 1)
		rooms = rooms->next;
	if (!rooms)
		return (NULL);
	((t_room *)rooms->content)->busy = 0;
	return (rooms->content);
}
