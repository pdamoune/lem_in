/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:09:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 16:16:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	ft_lstfree_lstlst(t_list *data)
{
	t_list *tmp;

	while (data)
	{
		ft_lstptrdel((t_list **)&data->content);
		tmp = data->next;
		free(data);
		data = tmp;
	}
}

void	ft_lstfree_lstlst_cont(t_list *data)
{
	t_list	*path;

	while (data)
	{
		ft_lstdel((t_list **)&data->content, &free);
		path = data->next;
		free(data);
		data = path;
	}
}

void	lem_free_rooms(t_list *rooms)
{
	t_list	*links;
	t_list	*tmp;

	while (rooms)
	{
		ft_strdel(&(((t_room *)rooms->content)->name));
		links = ((t_room *)rooms->content)->links;
		ft_lstptrdel((t_list **)&links);
		ft_memdel(&rooms->content);
		tmp = rooms->next;
		free(rooms);
		rooms = tmp;
	}
}

void	lem_free(int err)
{
	g_data ? ft_lstdel(&g_data, &free) : 0;
	lem_free_rooms(g_rooms);
	ft_lstfree_lstlst(g_paths);
	ft_lstfree_lstlst(g_multiple_paths);
	ft_lstptrdel(&g_ants_paths);
	ft_lstfree_lstlst_cont(g_visu);
	if (g_ants_end)
		free(g_ants_end);
	if (err)
	{
		ft_printf("ERROR\n");
		exit(-1);
	}
}
