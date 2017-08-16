/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_busy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 12:30:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/09 17:12:43 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_is_busy(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->busy
		&& !((t_room *)(path->content))->position)
			return (1);
		path = path->next;
	}
	return (0);
}
