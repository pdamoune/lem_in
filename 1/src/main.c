/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/22 22:31:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>

int		main(void)
{
	t_data	data;
	t_list	*l_rooms;
	t_list	*l_links;

	l_rooms = NULL;
	l_links = NULL;
	if (lem_parsing(&data, l_rooms, l_links, &data.ants) == -1)
		return (-1);
	return (0);
}
