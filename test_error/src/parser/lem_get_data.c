/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:58:32 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 19:25:27 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	lem_get_data(void)
{
	t_list	*tmp;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	tmp = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!tmp)
			tmp = ft_lstptr(line);
	 	else
			ft_lstadd_last(&tmp, ft_lstptr(line));
		i++;
	}
	v_data()->list_data = tmp;
	if (ret < 0)
		lem_error(GNL_ERROR);
	if (ret - i == 0)
		lem_error(EMPTY_FILE);
}
