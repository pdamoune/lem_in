/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:24:55 by philippe          #+#    #+#             */
/*   Updated: 2017/08/09 14:27:26 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Ajoute l’élément new en fin de liste.
*/

int		ft_lstadd_last(t_list **alst, t_list *new_list)
{
	t_list	*tmp;

	if (!(*alst))
	{
		*alst = new_list;
		return (1);
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	new_list->prev = tmp;
	tmp->next = new_list;
	return (1);
}
