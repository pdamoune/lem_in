/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_clr_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 12:26:13 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/09 17:10:10 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	lem_clr_path(t_list *path)
{
	while (path)
	{
		if (((t_room *)(path->content))->position != START - 1)
			((t_room *)(path->content))->busy = 0;
		path = path->next;
	}
}
