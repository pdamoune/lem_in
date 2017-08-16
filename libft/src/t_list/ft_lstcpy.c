/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:21:02 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/16 19:15:30 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** copy the hole list in a new list.
*/

t_list	*ft_lstcpy(t_list *src)
{
	t_list	*new_list;
	t_list	*tmp;

	if (!src)
		return (NULL);
	new_list = ft_lstptr(src->content);
	while ((src = src->next))
		ft_lstadd_last(&new_list, ft_lstptr(src->content));
	while (new_list->next)
	{
		tmp = new_list;
		new_list = new_list->next;
		new_list->prev = tmp;
	}
	new_list = ft_lstfirst(new_list);
	return (new_list);
}
