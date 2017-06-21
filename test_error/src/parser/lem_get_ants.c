/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 19:28:43 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 19:37:26 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	lem_get_ants(t_list *data)
{
	while (data && lem_is_com(data->content))
		data = data->next;
	if (!ft_isint(data->content))
		lem_error(NO_INT);
	if (!(v_data()->ants = ft_atoi(data->content)))
		lem_error(NO_ANTS);
	if (v_data()->ants < 0)
		lem_error(NEG_NB);
}
