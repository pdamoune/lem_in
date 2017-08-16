/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:24:55 by philippe          #+#    #+#             */
/*   Updated: 2017/08/07 17:45:31 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Ajoute l’élément new en tête de la liste.
*/

size_t	ft_lstlen(t_list *lst)
{
	size_t	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
