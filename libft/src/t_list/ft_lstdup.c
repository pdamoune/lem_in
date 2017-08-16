/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 06:30:05 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/07 18:15:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstdup(t_list *list)
{
	t_list	*dest;
	t_list	*tmp;

	dest = NULL;
	while (list)
	{
		tmp = ft_lstptr(list->content);
		if (!dest)
			dest = tmp;
		else
			ft_lstadd_last(&dest, tmp);
		list = list->next;
	}
	return (dest);
}
