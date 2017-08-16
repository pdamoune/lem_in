/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_multiple_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:27:17 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/10 23:20:04 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_multiple_paths(t_list **multiple, t_list *paths, int rayon)
{
	t_list *tmp;

	if (ft_lstlen(g_multiple_paths) + 1 == ft_lstlen(*multiple))
		return
		(ft_lstadd_last(&g_multiple_paths, ft_lstptr(ft_lstdup(*multiple))));
	while (paths)
	{
		if ((tmp = ft_lstlast(g_multiple_paths)))
			if (lem_lenmulti(tmp->content) > g_ants)
				return (0);
		if (!lem_is_busy(paths->content))
		{
			lem_busy_path(paths->content);
			ft_lstadd_last(multiple, ft_lstptr(paths->content));
			if (!lem_multiple_paths(multiple, g_paths, rayon))
				lem_clr_path(paths->content);
			ft_lstclr_last(multiple);
		}
		paths = paths->next;
	}
	return (0);
}
