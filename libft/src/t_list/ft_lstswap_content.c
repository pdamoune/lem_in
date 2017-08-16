/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:28:35 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 17:44:53 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstswap_content(t_list *lst1, t_list *lst2)
{
	t_list	*tmp;

	if (!lst1 || !lst2)
		return ;
	tmp = lst1->content;
	lst1->content = lst2->content;
	lst2->content = tmp;
}
