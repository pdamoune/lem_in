/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_multiple_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:27:17 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/07 18:50:28 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

// static void 	lem_multilist(t_list *m_paths)
// {
// 	t_list	*list_paths;
// 	int		i;
// 	int		j;
//
// 	i = 1;
// 	j = 1;
// 	ft_printf("{mag}%2cMULTIPLE\n---------------------\n", 0);
// 	if (!m_paths)
// 		return ;
// 	while (m_paths)
// 	{
// 		list_paths = m_paths->content;
// 		ft_printf("\n==========   %de multiple chemin   ==========\n", j++);
// 		// ft_putendl("test");
// 		while (list_paths)
// 		{
// 			ft_printf("%5s - ", ((t_room *)list_paths->content)->name);
// 			list_paths = list_paths->next;
// 		}
// 		i = 1;
// 		ft_printf("\n");
// 		m_paths = m_paths->next;
// 	}
// 	ft_printf("\n");
// 	ft_printf("=====================\n\n{eoc}");
// }

int		lem_multiple_paths(t_list **multiple, t_list *paths, int rayon)
{
	if (ft_lstlen(g_multiple_paths) + 1 == ft_lstlen(*multiple))
	{
		return (ft_lstadd_last(&g_multiple_paths, ft_lstptr(ft_lstdup(*multiple))));
	}
	// ft_printf("\r====== MULTIPLE_PATH ======");

	while (paths)
	{
		// ft_printf("multip = %d\r", i++);
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
