/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:23:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/11 19:12:28 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void 	lem_disp_data(t_list *data)
{
	if (!data)
		return ;
	ft_printf("%2cDATA\n---------------------\n", 0);
	while (data)
	{
		ft_printf("%s\n", data->content);
		data = data->next;
	}
	ft_printf("=====================\n\n");
}

void 	lem_disp_rooms(t_list *rooms)
{
	t_list *links;

	if (!rooms)
		return ;
	ft_printf("%2cROOMS\n---------------------\n", 0);
	while (rooms)
	{
		ft_printf("%s\n", ((t_room *)rooms->content)->name);
		links = ((t_room *)rooms->content)->links;
		while (links)
		{
			ft_printf("       %s\n", ((t_room *)links->content)->name);
			links = links->next;
		}
		// ft_printf("=== %s\n", ((t_room *)g_rooms->content)->name);
		rooms = rooms->next;
	}
	ft_printf("=====================\n\n");
}

void 	lem_display(int args, ...)
{
	va_list		ap;
	char		*arg;

	ft_printf("\n================= DISPLAY =================\n");
	va_start(ap, args);
	while (args--)
	{
		arg = va_arg(ap, char *);
		if (!ft_strcmp("ants", arg))
			ft_printf("%2cANTS = %d\n=====================\n", 0, g_ants);
		if (!ft_strcmp("rooms", arg))
			lem_disp_rooms(g_rooms);
		if (!ft_strcmp("data", arg))
			lem_disp_data(g_data);
	}
	ft_printf("=============== FIN DISPLAY =================\n\n");
}
