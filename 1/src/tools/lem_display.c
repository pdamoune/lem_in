/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:23:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/07 18:28:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void 	lem_disp_data(t_list *data)
{
	if (!data)
		return ;
	// ft_printf("%2cDATA\n---------------------\n", 0);
	while (data)
	{
		ft_printf("%s\n", data->content);
		data = data->next;
	}
	// ft_printf("=====================\n\n");
	ft_printf("\n");
}

void 	lem_disp_rooms(t_list *rooms)
{
	t_list *links;

	if (!rooms)
		return ;
	ft_printf("%2cROOMS\n---------------------\n", 0);
	while (rooms)
	{
		// if ((((t_room *)rooms->content)->position) != END - 1)
		// {
		// 	rooms = rooms->next;
		// 	continue ;
		// }
		ft_printf("|{mag}%d{eoc}| ", ((t_room *)rooms->content)->position);
		ft_printf("|{red}%d{eoc}| ", ((t_room *)rooms->content)->busy);
		ft_printf("|{gre}%-11d{eoc}| ", ((t_room *)rooms->content)->weight);
		ft_printf("{cya}%-2d{eoc} | ", ((t_room *)rooms->content)->room_number);
		ft_printf("{cya}%-10s{eoc} | ", ((t_room *)rooms->content)->name);
		links = ((t_room *)rooms->content)->links;
		while (links)
		{
			ft_printf("%-3s", ((t_room *)links->content)->name);
			if ((links = links->next))
				ft_printf(" - ");
		}
		ft_printf("\n");
		// ft_printf("=== %s\n", ((t_room *)g_rooms->content)->name);
		rooms = rooms->next;
	}
	ft_printf("=====================\n\n");
}

void 	lem_disp_paths(t_list *paths)
{
	t_list	*path;

	if (!g_paths)
		return ;
	ft_printf("%2c{cya}PATHS\n---------------------\n", 0);
	if (!paths)
		return ;
	while (paths)
	{
		path = paths->content;
		while (path)
		{
			ft_printf("%2s ", ((t_room *)path->content)->name);
			ft_printf("|%d| - ", ((t_room *)path->content)->busy);
			path = path->next;
		}
		ft_printf("\n");
		paths = paths->next;
	}
	ft_printf("\n");
	ft_printf("====================={eoc}\n\n");
}

void 	lem_multilist(t_list *paths)
{
	t_list	*path;

	if (!g_paths)
		return ;
	ft_printf("%2c{cya}MULTILIST\n---------------------\n", 0);
	if (!paths)
		return ;
	while (paths)
	{
		path = paths->content;
		while (path)
		{
			ft_printf("%2s ", ((t_room *)path->content)->name);
			ft_printf("|%d| - ", ((t_room *)path->content)->busy);
			path = path->next;
		}
		ft_printf("\n");
		paths = paths->next;
	}
}


void 	lem_disp_list(t_list *paths)
{
	t_room	*path;

	// ft_printf("%LIST\n---------------------\n", 0);
	if (!paths)
		return ;
	while (paths)
	{
		path = paths->content;
		ft_printf("{cya}|%-2d|{eoc}%5s - ", path->busy, path->name);
		paths = paths->next;
	}
	ft_printf("\n");
	// ft_printf("=====================\n\n");
}

void 	lem_disp_mult_paths(t_list *m_paths)
{
	t_list	*list_paths;
	t_list	*path;
	int		i;
	int		j;

	i = 1;
	j = 1;
	ft_printf("{mag}%2cMULTIPLE\n---------------------\n", 0);
	if (!m_paths)
		return ;
	while (m_paths)
	{
		list_paths = m_paths->content;
		ft_printf("\n==========   %de multiple chemin   ==========\n", j++);
		// ft_putendl("test");
		while (list_paths)
		{
			ft_printf("\n----   %de chemin   ----\n", i++);
			path = list_paths->content;
			while (path)
			{
				ft_printf("%5s - ", ((t_room *)path->content)->name);
				path = path->next;
			}
			list_paths = list_paths->next;
		}
		i = 1;
		ft_printf("\n");
		ft_printf("\n");
		m_paths = m_paths->next;
	}
	ft_printf("\n");
	ft_printf("=====================\n\n{eoc}");
}

void 	lem_display(int args, ...)
{
	va_list		ap;
	char		*arg;

	// ft_printf("\n{bla}================= DISPLAY ================={eoc}\n");
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
		if (!ft_strcmp("list", arg))
			lem_disp_list(va_arg(ap, t_list *));
		if (!ft_strcmp("multilist", arg))
			lem_multilist(va_arg(ap, t_list *));
		// if (!ft_strcmp("multiple", arg))
	}
	// ft_printf("{bla}=============== FIN DISPLAY =================\n\n{eoc}");
}
