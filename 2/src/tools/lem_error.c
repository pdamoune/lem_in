/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:09:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/10 18:29:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void 		lem_free_data(t_list *data)
{
	t_list	*tmp;

	while (data)
	{
		ft_memdel(&data->content);
		tmp = data->next;
		free(data);
		data = tmp;
	}
	g_data = NULL;
}

void		lem_free(int err)
{
	err <= NEG_ANTS ? lem_free_data(g_data) : 0;
	exit (-1);
}
