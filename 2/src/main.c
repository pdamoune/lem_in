/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/04 16:44:41 by pdamoune         ###   ########.fr       */
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
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
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
		if (lem_len_multiple(multiple->content) >= ants || !(multiple->next))
			break ;
		multiple = multiple->next;
	}
	multiple = multiple->content;
	return (multiple);
}

int		lem_send_ants(int ants)
{
	t_list	*path;

	while (ants)
	{
		path = lem_which_multiple(ants);

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
