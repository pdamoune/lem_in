/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/20 03:15:06 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>

int		main(void)
{
	t_list	*list_rooms;
	t_list	*list_links;
	int		ants;

	ants = 0;
	list_rooms = NULL;
	list_links = NULL;
	if (lem_parsing(list_rooms, list_links, &ants) == -1)
		return (-1);
	return (0);
}
