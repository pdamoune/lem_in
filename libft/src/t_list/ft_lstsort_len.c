/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:31:13 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/20 17:32:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int		ft_lstsortlen(t_list *list)
{
	t_list	*tmp;
	int		len;

	tmp = list;
	while (tmp)
	{
		len = ft_lstlen(tmp->content);
		if (tmp->next && ft_lstlen(tmp->next->content) < (size_t)len)
		{
			ft_lstswap_content(tmp, tmp->next);
			tmp = list;
		}
		else
			tmp = tmp->next;
	}
	return (len);
}
