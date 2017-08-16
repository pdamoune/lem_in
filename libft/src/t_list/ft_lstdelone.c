/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:25:01 by philippe          #+#    #+#             */
/*   Updated: 2017/08/15 17:44:29 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et
** libère la mémoire du contenu de ce maillon avec la fonction
** del passée en paramètre puis libère la mémoire du maillon
** en lui même avec free(3). La mémoire du champ next ne
** doit en aucun cas être libérée. Pour terminer, le pointeur sur
** le maillon maintenant libéré doit être mis à NULL (de manière
** similaire à la fonction ft_memdel de la partie obligatoire).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*next;

	del((*alst)->content, (*alst)->content_size);
	prev = (*alst)->prev;
	next = (*alst)->next;
	if (!prev)
	{
		free(*alst);
		*alst = next;
	}
	else
	{
		prev->next = next;
		if (next)
			next->prev = prev;
		free(*alst);
	}
}
