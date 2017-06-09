/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:50:31 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/09 20:49:55 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_get_data(t_list **data)
{
	t_list	*tmp;
	char	*line;
	int		ret;
	int		i;

	i = -1;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		tmp = ft_lstptr(line);
		!*data ? *data = tmp : ft_lstadd_last(*data, tmp);
		i++;
	}
	return (i + ret + 1);
}
