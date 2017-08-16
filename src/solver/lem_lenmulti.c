/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_lenmulti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 17:15:32 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/14 17:15:46 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_lenmulti(t_list *multi)
{
	t_list	*tmp;
	t_list	*path;
	int		len;

	len = 0;
	if (!(tmp = multi))
		return (0);
	while (multi)
	{
		path = multi->content;
		len += ft_lstlen(path);
		multi = multi->next;
	}
	len /= ft_lstlen(tmp);
	return (len);
}
