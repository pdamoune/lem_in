/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/06 14:35:19 by pdamoune         ###   ########.fr       */
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
	while (multiple)
	{
		if (ft_lstlen(multiple->content) == (size_t)ants || !(multiple->next))
			break ;
		multiple = multiple->next;
	}
	multiple = multiple->content;
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
	t_room	*room;
	// int		next;

	// int i = 0;
	ants = 0;
	path_tmp = NULL;
	while (g_ants > ants)
	{
		ft_lstadd_last(&path_tmp, lem_which_multiple(g_ants - ants));
		ants += ft_lstlen(path_tmp);
		path = path_tmp;
	}
	// path_tmp = path;
	// int i = 0;
	while (path_tmp)
	{
		// ft_printf ("ants = %3d | ", ++i);
		if ((path = path_tmp->content))
		{
			while (path)
			{
				room = path->content;
				if (!room->busy)
				{
					room->busy = 1;
					ft_printf("name %s\n", room->name);
				}
				path = path->next;
			}
		}
		// path = path_tmp->content;
		// while (path)
		{
		}
		// lem_display_ants()
		// if (!(path = path->next))
		// lem_display_ants(path);

		// {
		path_tmp = path_tmp->next;
		// 	i = 0;
		// }
		// break ;
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
