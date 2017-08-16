/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:55:21 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/20 12:31:30 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list		*ft_lstlast(t_list *list)
{
	t_list		*last;

	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	last = list;
	return (last);
}
