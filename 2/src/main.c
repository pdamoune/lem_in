/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/07 15:09:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int 	lem_len_multiple(t_list *multiple)
{
	int		len;
	t_list	*tmp;

	len = 0;
	while (multiple)
	{
		tmp = multiple->content;
		while ((tmp = tmp->next))
			len++;
		multiple = multiple->next;
	}
	return (len);
}

t_list	*lem_which_multiple(ants)
{
	t_list	*multiple;

	multiple = g_multiple_paths;
	// exit (0);
	while (multiple)
	{
		if (ft_lstlen(multiple->content) == (size_t)ants || !(multiple->next))
		{
			break ;
		}
		multiple = multiple->next;
	}
	multiple = ft_lstdup(multiple->content);
	return (multiple);
}

void 	lem_display_ants(t_list *paths)
{
	t_list	*ants;
	t_room	*room;
	int		i = 0;

	while (paths)
	{
		i++;
		ants = ((t_list *)paths->content)->next;
		if (ants && (room = ants->content))
		{
			ft_printf("L%d-%s ", i, room->name);
		}

		paths = paths->next;
	}
}

int		lem_send_ants(int ants)
{
	t_list	*path;
	t_list	*path_tmp;
	t_list	*path_tmp2;
	t_room	*room;
	t_room	*next_room;
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
	// while (path_tmp2)
	// {
	// 	lem_display(1, "list", path_tmp2->content);
	// 	path_tmp2 = path_tmp2->next;
	// }
	// int i = 0;
	while (g_ants)
	{
		while (path_tmp)
		{
			// lem_display(1, "list", path);
			if ((path = path_tmp->content))
			{
				room = path->content;
				next_room = path->next->content;
				if (!next_room->busy)
				{
					// lem_display(1, "list", path);
					if (room->position == START - 1)
					{
						ants++;
						// ft_printf("start\n");
						ft_printf("L%d-%s", ants, next_room->name);
						next_room->busy = ants;
						path_tmp->content = path->next;
						path = path->next;
					}
					else if (next_room->position == END - 1)
					{
						// ft_printf("end\n");
						ft_printf("L%d-%s", room->busy, next_room->name);
						room->busy = 0;
						path_tmp->content = NULL;
						g_ants--;
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
					ft_printf(" ");
				}
				// lem_display(1, "list", path);
			}
			path_tmp = path_tmp->next;
		}
		ft_putendl("");
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
	lem_display(2, "rooms", "multiple");
	lem_send_ants(g_ants);

	// lem_display(1, "multiple");

	lem_free(0);
	return (0);
}
