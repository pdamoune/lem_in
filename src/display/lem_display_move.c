/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:00:04 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 18:15:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

char	*g_color[11] =
{
	"{whi}{bol}",
	"{gre}{bol}",
	"{mag}{bol}",
	"{red}{bol}",
	"{cya}{bol}",
	"{blu}{bol}",
	"{yel}{bol}",
	"{gre}{bol}",
	"{mag}{bol}",
	"{yel}{bol}",
	NULL
};

void	lem_disp_start(int fd, t_visu *last, int *start, char *dash)
{
	int		ant;
	int		j;

	j = 0;
	if (last && last->ant > *start)
		*start = last->ant;
	ant = g_ants;
	ft_printf("%@%s{cya}%s|%21cSTART%22c|\n%s", fd, CLEAR, dash, 32, 32, dash);
	while (ant > *start)
	{
		ft_printf("%@%s%4d{eoc} ", fd, g_color[ant % 6], ant);
		if (!(++j % 10))
			ft_printf("%@\n", fd);
		ant--;
	}
	ft_printf("%@{eoc}\n", fd);
}

void	lem_disp_end(int fd, char *dash)
{
	unsigned	*ant;
	int			i;

	i = -1;
	ant = g_ants_end;
	ft_printf("%@{red}%s|%21cARRIVE%21c|\n%s\n", fd, dash, 32, 32, dash);
	while (++i <= g_ants)
	{
		if (ant[i])
			ft_printf("%@%s%4d{eoc} ", fd, g_color[ant[i] % 6], ant[i]);
		if (ant[i] && !((i) % 10))
			ft_printf("%@\n", fd);
	}
}

void	lem_disp_paths(int fd, t_list *multiple, t_list *path, t_room *room)
{
	t_list *path_tmp;

	ft_printf("%@\n", fd);
	path = multiple->content;
	while (path)
	{
		path_tmp = path->content;
		while ((path_tmp = path_tmp->next) && path_tmp->next)
		{
			room = path_tmp->content;
			ft_printf("%@|{bla}{bol}{WHI} %-5s{eoc}{EOC}", fd, room->name);
		}
		ft_printf("%@|\n", fd) && (path_tmp = path->content);
		while ((path_tmp = path_tmp->next) && path_tmp->next)
		{
			room = path_tmp->content;
			if (room->busy)
				ft_printf("%@%s| %-3d{WHI}🐜 {EOC}{eoc}", fd,
				g_color[room->busy % 10], room->busy);
			else
				ft_printf("%@| %6c{eoc}", fd, 0);
		}
		ft_printf("%@|\n\n", fd) && (path = path->next);
	}
}

void	lem_display_move(t_visu *visu)
{
	static int	start = 0;
	char		dash[52];
	int			fd;

	if ((fd = open("/dev/ttys003", O_WRONLY)) == -1)
		return ;
	ft_memset(dash, '-', 50);
	dash[50] = '\n';
	dash[51] = 0;
	ft_printf("%@%s", fd, CLEAR);
	lem_disp_start(fd, visu, &start, dash);
	lem_disp_paths(fd, ft_lstlast(g_multiple_paths), NULL, NULL);
	lem_disp_end(fd, dash);
}
