/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:24:59 by philippe          #+#    #+#             */
/*   Updated: 2017/08/16 16:15:38 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et
** libère la mémoire de ce maillon et celle de tous ses successeurs
** l’un après l’autre avec del et free(3). Pour terminer,
** le pointeur sur le premier maillon maintenant libéré doit être
** mis à NULL (de manière similaire à la fonction ft_memdel de
** la partie obligatoire).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*nxt;

	if (!alst || !del)
		return ;
	if ((*alst)->prev)
		(*alst)->prev->next = NULL;
	while (*alst)
	{
		nxt = (*alst)->next;
		if ((*alst)->content)
			del((*alst)->content);
		free(*alst);
		*alst = nxt;
	}
	ft_memdel((void *)&(*alst));
}
