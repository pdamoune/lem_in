/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 21:04:55 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/09 21:43:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_get_ants(t_list *data, int *ants)
{
	while (data && lem_is_com(data->content))
		data = data->next;
	if (!ft_isint(data->content))
		return (-1);
	if (!(*ants = ft_atoi(data->content)))
		return (0);
	if (*ants < 0)
		return (-2);
	return (1);
}
