/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:39:09 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 17:44:12 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstcheck(t_list *list, void (*disp)(void *))
{
	while (list)
	{
		if (list->prev && (list = list->prev))
			continue ;
	}
}
