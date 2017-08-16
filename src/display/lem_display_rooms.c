/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:58:43 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 18:36:08 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static void		lem_disp_links(int fd, t_list *links)
{
	while (links)
	{
		ft_printf("%@%s", fd, ((t_room *)links->content)->name);
		if ((links = links->next))
			ft_printf("%@ - ", fd);
	}
	ft_printf("%@\n", fd);
}

static void		lem_disp_rooms(int fd, t_list *rooms, t_room *room)
{
	while (rooms)
	{
		room = rooms->content;
		if (!room->position)
		{
			ft_printf("%@{gre} %-13s {eoc}| {blu}", fd, room->name);
			lem_disp_links(fd, room->links);
		}
		rooms = rooms->next;
	}
	(void)&fd;
}

static void		lem_disp_head(int fd, char *dash)
{
	t_room *room;

	ft_printf("%@%s", fd, CLEAR);
	ft_printf("%@\n{bol}{red}", fd);
	ft_printf("%@%3cFOURMIS : %d\n\n", fd, 0, g_ants);
	ft_printf("%@{eoc}", fd);
	ft_printf("%@%s|%21c{gre}ROOMS{eoc}%22c|\n%s\n", fd, dash, 32, 32, dash);
	room = lem_get_start(g_rooms);
	ft_printf("%@ {cya}START = %-5s | ", fd, room->name);
	lem_disp_links(fd, room->links);
	room = lem_get_end(g_rooms);
	ft_printf("%@ {cya}END   = %-5s | ", fd, room->name);
	lem_disp_links(fd, room->links);
	ft_printf("%@{eoc}\n NAME%11c| LINKS\n%.15s|%.36s\n", fd, 0, dash, dash);
}

void			lem_display_rooms(t_list *rooms)
{
	char	dash[52];
	int		fd;

	if ((fd = open("/dev/ttys001", O_WRONLY)) == -1 || !rooms)
		return ;
	ft_memset(dash, '-', 50);
	dash[50] = '\n';
	dash[51] = 0;
	lem_disp_head(fd, dash);
	lem_disp_rooms(fd, rooms, NULL);
}
