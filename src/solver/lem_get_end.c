/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 16:28:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/09 17:11:32 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

t_room		*lem_get_end(t_list *rooms)
{
	while (rooms && ((t_room *)rooms->content)->position != END - 1)
		rooms = rooms->next;
	if (!rooms)
		return (NULL);
	return (rooms->content);
}
