#include "../../include/lem_in.h"

int		lem_nb_paths_max(t_list *paths)
{
	t_room	*room;
	int		paths_max;

	paths_max = 0;
	while (paths)
	{
		room = ((t_list *)paths->content)->content;
		if (!room->busy)
		{
			 room->busy = 1;
			 paths_max++;
		}
		paths = paths->next;
	}
	(void)&paths;
	return (paths_max);
}


int 	lem_is_possible(t_list *path, int rayon)
{
	t_room	*room;

	while (path)
	{
		room = path->content;
		if (room->busy || room->weight > rayon)
			return (1);
		path = path->next;
	}
	return (0);
}

int		lem_check_path(t_list *paths, t_list *other_path)
{
	int		r1;
	int		r2;
	t_list	*tmp;

	tmp = other_path;
	while (paths)
	{
		r1 = ((t_room *)paths->content)->room_number;
		while (tmp)
		{
			r2 = ((t_room *)tmp->content)->room_number;
			if (r1 == r2)
				return (0);
			tmp = tmp->next;
		}
		tmp = other_path;
		paths = paths->next;
	}
	return (1);
}

int 	lem_get_path(t_list *path, t_list *links, t_room *room, int rayon)
{
	static int	len = 1;
	t_list		*links_tmp;
	t_room		*room_tmp;

	if (room->position == END - 1 || len >= rayon)
		return (room->position == END - 1 && len == rayon ? 1 : 0);
	links_tmp = links;
	while (links_tmp)
	{
		room_tmp = links_tmp->content;
		if (room_tmp->weight < rayon - len && !room_tmp->busy && room_tmp->position != START - 1)
		{
			room_tmp->busy = 1;
			len++;
			ft_lstadd_last(&path, ft_lstptr(room_tmp));
			if (lem_get_path(path, room_tmp->links, room_tmp, rayon))
			{
				ft_lstadd_last(&g_paths, ft_lstptr(ft_lstdup(path)));
			}
			ft_lstclr_last(&path);
			len--;
			if (room_tmp->position != START - 1)
				room_tmp->busy = 0;
		}
		links_tmp = links_tmp->next;
	}
	// if (len == 1)
	// {
	// 	rayon++;
	// 	lem_get_path(path, links, room, rayon);
	// }
	return (0);
}

int		lem_len_multiple(t_list *multiple)
{
	int		len;

	len = 0;
	while (multiple)
	{
		len += ft_lstlen(multiple->content);
		multiple = multiple->next;
	}
	return (len);
}

int		lem_try_rayon(t_list **multiple, t_list *paths, int len)
{

	if (ft_lstlen(g_multiple_paths) + 1 == ft_lstlen(*multiple))
	{
		ft_lstadd_last(&g_multiple_paths, ft_lstptr(ft_lstdup(*multiple)));
		return (1);
	}
	while (paths)
	{
		if (!lem_is_busy(paths->content))
		{
			lem_busy_path(paths->content);
			ft_lstadd_last(multiple, ft_lstptr(paths->content));
			if (lem_try_rayon(multiple, g_paths, len))
			{
				// 2 eme algorythme
				// return (1);
			}
			{
				lem_clr_path(paths->content);
				ft_lstclr_last(multiple);
			}
		}
		paths = paths->next;
	}

	return (0);
}

int		lem_lenmax_multiple(t_list *list1, t_list *list2)
{
	int		len1;
	int		len2;

	len1 = ft_lstlen(list1);
	len2 = ft_lstlen(list2);
	return (len1 < len2 ? len1 : len2);
}

int		lem_test_paths(t_list *path, t_room *room, int stop, int rayon)
{
	t_list	*multiple;
	t_list	*links;
	// int ret;

	path = ft_lstptr(lem_get_start(g_rooms));
	links = room->links;
	while (++rayon < (int)ft_lstlen(g_rooms))
	{
		lem_get_path(path, room->links, room, rayon);
		if (!g_paths)
			continue ;
		// ft_printf("rayon = %d\n", rayon);
		multiple = NULL;
		lem_try_rayon(&multiple, g_paths, ft_lstlen(g_multiple_paths));
		lem_display(2, "multiple", "paths");

		lem_clr_path(g_rooms);
		if ((int)ft_lstlen(g_multiple_paths) >= stop)
			break ;
	}
	return (1);
}

int		lem_get_paths(void)
{
	t_room	*start;
	t_room	*end;
	int		stop;

	start = lem_get_start(g_rooms);
	end = lem_get_end(g_rooms);
	stop = lem_lenmax_multiple(start->links, end->links);
	lem_test_paths(NULL, start, stop, 0);
	return (1);
}
