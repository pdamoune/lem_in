/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:14:26 by philippe          #+#    #+#             */
/*   Updated: 2017/07/13 02:49:07 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Compare data in the list *list with the cmp function.
** Return the first chain which occures or NULL if data is not founded.
**
** Exemple of cmp :
**
** int		cmp(t_list *list, char *data)
** {
**		return (ft_strcmp(list->content->name, data))
** }
*/

t_list	*ft_lstfind(t_list *list, void *data, int (*cmp)())
{
	if (!list || !data || !cmp)
		return (NULL);
	while (list->prev)
		list = list->prev;
	while (list && cmp(list->content, data))
		list = list->next;
	return (list);
}
