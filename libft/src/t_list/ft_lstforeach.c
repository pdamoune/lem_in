/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:05:44 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/20 12:31:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstforeach(t_list *list, void (*f)(void *))
{
	if (!list)
		return ;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}
