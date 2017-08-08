/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/08 20:43:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		lem_lenmulti(t_list *multi)
{
	t_list	*tmp;
	t_list	*path;
	int		len;

	len = 0;
	tmp = multi;
	while (multi)
	{
		path = multi->content;
		len += ft_lstlen(path);
		multi = multi->next;
	}
	len /= ft_lstlen(tmp);
	return (len);
}

t_list	*lem_which_multiple(ants)
{
	t_list	*multiple;
	int 	len;

	multiple = g_multiple_paths;
	// exit (0);
	while (multiple)
	{
		len = lem_lenmulti(multiple->content);
		if (len >= ants || !(multiple->next))
		{
			if (!multiple->next)
				break ;
			if (len != lem_lenmulti(multiple->next->content))
				break ;
		}
		multiple = multiple->next;
	}
	multiple = ft_lstdup(multiple->content);
	return (multiple);
}

int		lem_send_ants(int ants)
{
	t_list	*path;
	t_list	*path_tmp;
	t_list	*path_tmp2;
	t_room	*room;
	t_room	*next_room;
	int		nb_ants;
	int i = 0;
	// int		next;

	// int i = 0;
	ants = 0;
	path_tmp = NULL;
	while (g_ants > ants)
	{
		ft_lstadd_last(&path_tmp, lem_which_multiple(g_ants - ants));
		ants = ft_lstlen(path_tmp);
	}

	path = path_tmp;
	ants = 0;
	path_tmp2 = path_tmp;
	nb_ants = g_ants;
	while (g_ants)
	{
		while (path_tmp)
		{
			if ((path = path_tmp->content))
			{
				room = path->content;
				next_room = path->next->content;
				if (!next_room->busy)
				{
					if (i)
						ft_printf(" ");
					if (next_room->position == END - 1)
					{
						if (room->position == START - 1)
							room->busy = ++ants;
						ft_printf("L%d-%s", room->busy, next_room->name);
						room->busy = 0;
						path_tmp->content = NULL;
						g_ants--;
					}
					else if (room->position == START - 1)
					{
						if (ants < nb_ants)
						{
							ants++;
							ft_printf("L%d-%s", ants, next_room->name);
							next_room->busy = ants;
							path_tmp->content = path->next;
						}
						path = path->next;

					}
					else
					{
						// ft_printf("autre\n");
						ft_printf("L%d-%s", room->busy, next_room->name);
						next_room->busy = room->busy;
						room->busy = 0;
						path_tmp->content = path->next;
						path = path->next;
					}
					i = 1;
				}
				// lem_display(1, "list", path);
			}
			path_tmp = path_tmp->next;
		}
		ft_putendl("");
		i = 0;
		path_tmp = path_tmp2;
	}
	return (0);
}

int		main(void)
{
	lem_set_globales();
	lem_parser();

	lem_set_weight();
	lem_solver();
	lem_display(1, "data");
	// lem_display(1, "multiple", g_data);
	lem_send_ants(g_ants);

	// lem_display(1, "multiple");

	lem_free(0);
	return (0);
}
