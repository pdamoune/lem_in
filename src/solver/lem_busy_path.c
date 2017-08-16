/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_busy_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 12:28:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/09 17:09:46 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	lem_busy_path(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->position != END - 1)
			((t_room *)(path->content))->busy = 1;
		path = path->next;
	}
}
