/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:47:39 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/10 16:51:25 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_get_data(void)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0 && *line)
		!g_data ? g_data = ft_lstptr(line) :
		ft_lstadd_last(&g_data, ft_lstptr(line));
	if (ret == -1)
		return (ft_error(1, BAD_FD, INFO, "fd = -1", &lem_free));
	return (ret + 1);
}
