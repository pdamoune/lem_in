/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display_multiple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 19:35:07 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 12:35:18 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static void	lem_set_s(char *s, int i)
{
	if (i % 10 == 1 && i != 11)
		ft_strcpy(s, "st");
	else if (i % 10 == 2 && i != 12)
		ft_strcpy(s, "nd");
	else if (i % 10 == 3 && i != 13)
		ft_strcpy(s, "rd");
	else
		ft_strcpy(s, "th");
}

static void	lem_disp_multiple(int fd, t_list *list_paths, t_list *path)
{
	static int	i = 1;
	int			j;
	char		s[3];

	j = 1;
	lem_set_s(s, i);
	ft_printf("%@\n===%13c%d%s multiple path%14c===\n", fd, 32, i++, s, 32);
	while (list_paths)
	{
		lem_set_s(s, j);
		ft_printf("%@\n%3d%-s path :%5c", fd, j++, s, 0);
		path = list_paths->content;
		while (path)
		{
			ft_printf("%@%5s - ", fd, ((t_room *)path->content)->name);
			path = path->next;
		}
		list_paths = list_paths->next;
		ft_printf("%@\n", fd);
	}
	ft_printf("%@\n", fd);
}

void		lem_display_multiple(t_list *multiple)
{
	char	dash[52];
	int		fd;

	if ((fd = open("/dev/ttys002", O_WRONLY)) == -1 || !multiple)
		return ;
	ft_memset(dash, '-', 50);
	dash[50] = '\n';
	dash[51] = 0;
	ft_printf("%@%s", fd, CLEAR);
	ft_printf("%@{mag}%s|%20cMULTIPLE%20c|\n%s\n", fd, dash, 32, 32, dash);
	while (multiple)
	{
		lem_disp_multiple(fd, multiple->content, NULL);
		multiple = multiple->next;
	}
}
