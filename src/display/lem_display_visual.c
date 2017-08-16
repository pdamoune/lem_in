/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display_visual.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:17:57 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 12:43:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	lem_disp_single(int visual)
{
	char	buf[2];

	if (visual == VISUAL)
		return ;
	ft_bzero(buf, 2);
	if (visual == SINGLE)
		while (buf[0] != '\n')
			read(1, buf, 1);
	visual == AUTO_SINGLE ? sleep(1) : 0;
}

void	lem_disp_line(int visual)
{
	char	buf[2];

	if (visual == VISUAL)
		return ;
	ft_bzero(buf, 2);
	if (visual == LINE)
		while (buf[0] != '\n')
			read(1, buf, 1);
	visual == AUTO_LINE ? sleep(1) : 0;
}

void	lem_display_visual(int visual, t_list *visu, t_list *tmp, t_visu *ant)
{
	int		i;
	char	buf[2];

	i = 0;
	while (visu && (tmp = visu->content))
	{
		while (tmp && !(buf[0] = 0))
		{
			(ant = tmp->content) && ft_printf("L%d-%s", ant->ant, ant->room);
			if (!((t_room *)(ant->cur_room))->position)
				((t_room *)(ant->cur_room))->busy = ant->ant;
			if ((ant->cur_room)->position == END - 1)
			{
				while (g_ants_end[++i])
					;
				g_ants_end[i] = ant->ant;
			}
			((t_room *)(ant->prev_room))->busy = 0;
			visual ? lem_display_move(tmp->content) : 0;
			visual ? lem_disp_single(visual) : 0;
			(tmp = tmp->next) && ft_printf(" ");
		}
		visual ? lem_disp_line(visual) : 0;
		ft_printf("\n") && (visu = visu->next);
	}
}
