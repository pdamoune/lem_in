/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 00:04:55 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/10 00:20:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_get_links(t_data *data, t_list *list_data, t_list *l_rooms, t_list **l_links)
{
	t_link	*link;
	char	*line;
	t_room	room;
	t_list	*tmp;

	link = ft_memalloc(sizeof(t_link));
	while ((list_data = list_data->next))
	{
		line = ft_strdup(list_data->content);
		if ((lem_is_com(line)) > 0 || lem_is_room(data, &room, line))
		{
			ft_strdel(&line);
			continue ;
		}
		if (!lem_is_link(l_rooms, link, line))
		{
			ft_strdel(&line);
			return (0);
		}
		tmp = ft_lstnew(link, sizeof(t_link));
		!*l_links ? *l_links = tmp : ft_lstadd_last(*l_links, tmp);
		link = ft_memalloc(sizeof(t_link));
	}
	return (1);
}
