/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:23:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/20 18:57:11 by pdamoune         ###   ########.fr       */
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

void 	lem_disp_paths(t_list *paths)
{
	t_list	*path;

	ft_printf("%2cPATHS\n---------------------\n", 0);
	if (!paths)
		return ;
	while (paths)
	{
		path = paths->content;
		while (path)
		{
			ft_printf("%s - ", ((t_room *)path->content)->name);
			path = path->next;
		}
		ft_printf("\n");
		paths = paths->next;
	}
	ft_printf("\n");
	ft_printf("=====================\n\n");
}

void 	lem_disp_mult_paths(t_list *m_paths)
{
	t_list	*list_paths;
	t_list	*path;
	int		i;

	i = 1;
	ft_printf("%2cPATHS\n---------------------\n", 0);
	if (!m_paths)
		return ;
	while (m_paths)
	{
		list_paths = m_paths->content;
		while (list_paths)
		{
			ft_printf("----   %d chemins   ----\n", i++);
			path = list_paths->content;
			while (path)
			{
				ft_printf("%s - ", ((t_room *)path->content)->name);
				path = path->next;
			}
			list_paths = list_paths->next;
		}
		ft_printf("\n");
		m_paths = m_paths->next;
	}
	ft_printf("\n");
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
		if (!ft_strcmp("paths", arg))
			lem_disp_paths(g_paths);
		if (!ft_strcmp("data", arg))
			lem_disp_data(g_data);
		if (!ft_strcmp("multiple", arg))
			lem_disp_mult_paths(g_multiple_paths);
	}
	ft_printf("=============== FIN DISPLAY =================\n\n");
}
