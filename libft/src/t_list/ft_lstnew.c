/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:25:08 by philippe          #+#    #+#             */
/*   Updated: 2017/08/09 14:42:18 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne un maillon “frais”. Les
** champs content et content_size du nouveau maillon sont
** initialisés par copie des paramètres de la fonction. Si le paramètre
** content est nul, le champs content est initialisé à
** NULL et le champs content_size est initialisé à 0 quelque
** soit la valeur du paramètre content_size. Le champ next
** est initialisé à NULL. Si l’allocation échoue, la fonction renvoie
** NULL.
*/

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
		return (newlst);
	newlst->content = ft_memalloc(content_size);
	ft_memcpy(newlst->content, content, content_size);
	newlst->content_size = content_size;
	newlst->next = NULL;
	newlst->prev = NULL;
	return (newlst);
}
