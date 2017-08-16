/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:25:03 by philippe          #+#    #+#             */
/*   Updated: 2017/08/15 20:19:47 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction
** f.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
