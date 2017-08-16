/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:55:21 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/20 12:30:50 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list		*ft_lstfirst(t_list *list)
{
	t_list		*last;

	if (!list)
		return (NULL);
	while (list->prev)
		list = list->prev;
	last = list;
	return (last);
}
