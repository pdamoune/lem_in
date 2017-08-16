/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:25:06 by philippe          #+#    #+#             */
/*   Updated: 2017/06/16 13:07:32 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction
** f et crée une nouvelle liste “fraiche” avec malloc(3) résultant
** des applications successives. Si une allocation échoue,
** la fonction renvoie NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;

	if (!lst)
		return (NULL);
	dest = f(lst);
	dest->next = ft_lstmap(lst->next, f);
	return (dest);
}
