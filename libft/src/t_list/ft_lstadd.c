/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:24:55 by philippe          #+#    #+#             */
/*   Updated: 2017/06/16 13:03:32 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Ajoute l’élément new en tête de la liste.
*/

void	ft_lstadd(t_list **alst, t_list *new_list)
{
	t_list	*prev;

	if (!(*alst && new_list))
		return ;
	new_list->next = *alst;
	prev = (*alst)->prev;
	(*alst)->prev = new_list;
	new_list->prev = prev;
	*alst = new_list;
}
