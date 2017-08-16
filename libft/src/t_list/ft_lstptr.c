/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:37:35 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/09 14:47:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Create and malloc a list with the size of a ptr.
** set the content to *ptr.
** return the list.
*/

t_list	*ft_lstptr(void *ptr)
{
	t_list	*tmp;

	tmp = ft_memalloc(sizeof(t_list));
	tmp->content = ptr;
	return (tmp);
}
