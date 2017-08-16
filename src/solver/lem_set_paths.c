/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_set_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 17:19:53 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 18:29:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

t_list	*lem_which_multiple_paths(int ants)
{
	t_list	*multiple;
	int		len;

	multiple = g_multiple_paths;
	while (multiple)
	{
		len = lem_lenmulti(multiple->content);
		if ((multiple->prev && len >= ants
			&& len <= (int)ft_lstlen(multiple->prev->content))
			|| !(multiple->next))
			break ;
		multiple = multiple->next;
	}
	return (ft_lstdup(multiple->content));
}

void	lem_set_paths(int ants)
{
	while ((ants = ft_lstlen(g_ants_paths)) < g_ants)
		ft_lstadd_last(&g_ants_paths, lem_which_multiple_paths(ants));
}
