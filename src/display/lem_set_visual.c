/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_set_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:34:52 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 18:44:41 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	lem_visual(int ant, t_room *prev, t_room *room)
{
	t_visu *move;

	move = ft_memalloc(sizeof(t_visu));
	move->ant = ant;
	move->room_nb = room->room_number;
	move->room = room->name;
	move->cur_room = room;
	move->prev_room = prev;
	ft_lstadd_last(&g_tmp, ft_lstptr(move));
}

void	lem_start_end(t_list *l_ant, t_room *room, t_room *next, int *nb_ants)
{
	static int	ants = 0;

	if (next->position == END - 1)
	{
		if (room->position == START - 1)
			room->busy = ++ants;
		lem_visual(room->busy, room, next);
		room->busy = 0;
		l_ant->content = NULL;
		(*nb_ants)--;
	}
	else if (room->position == START - 1)
	{
		if (ants < g_ants)
		{
			ants++;
			next->busy = ants;
			lem_visual(next->busy, room, next);
			l_ant->content = ((t_list *)l_ant->content)->next;
		}
	}
}

void	lem_middle(t_list *list_ant, t_room *room, t_room *next)
{
	lem_visual(room->busy, room, next);
	next->busy = room->busy;
	room->busy = 0;
	list_ant->content = ((t_list *)list_ant->content)->next;
}

void	lem_srt_mdl(t_list *l_ants, t_room *room, t_room *next, int *nb_ants)
{
	if ((next->position == END - 1 || room->position == START - 1))
		lem_start_end(l_ants, room, next, nb_ants);
	else
		lem_middle(l_ants, room, next);
}

void	lem_set_visual(t_list *l_ants, t_list *path, t_room *room, t_room *next)
{
	t_list	*backup;
	int		nb_ants;

	nb_ants = g_ants;
	backup = l_ants;
	while (nb_ants && (l_ants = backup))
	{
		while (l_ants)
		{
			if ((path = l_ants->content))
			{
				room = path->content;
				next = path->next->content;
				if (!next->busy)
				{
					lem_srt_mdl(l_ants, room, next, &nb_ants);
					path = path->next;
				}
			}
			l_ants = l_ants->next;
		}
		ft_lstadd_last(&g_visu, ft_lstptr(g_tmp));
		g_tmp = NULL;
	}
}
