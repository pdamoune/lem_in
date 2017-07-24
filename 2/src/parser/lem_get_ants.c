/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:54:50 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/24 15:46:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_get_ants(t_list *data)
{
	while (data && lem_is_com(data->content) > 0)
		data = data->next;
	if (!ft_isint(data->content))
		return (ft_error(1, BAD_ANTS, INFO, "Ants' number is not an int"
		, &lem_free));
	if (!(g_ants = ft_atoi(data->content)))
		return (ft_error(1, NO_ANTS, INFO, "No Ants", &lem_free));
	if (g_ants < 0)
		return (ft_error(1, NEG_ANTS, INFO, "Ants negative", &lem_free));
	return (1);
}
