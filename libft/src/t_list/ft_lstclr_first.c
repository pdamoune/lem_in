/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 23:14:25 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 14:37:16 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclr_first(t_list **lst)
{
	t_list *tmp;

	if (!(*lst))
		return ;
	tmp = *lst;
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		*lst = tmp->next;
		(*lst)->prev = NULL;
		tmp->content = NULL;
		free(tmp->prev);
		tmp->prev = NULL;
	}
}
