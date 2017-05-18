/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/18 02:21:43 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		main(void)
{
	int		nb_ants;
	// char 	*line;
	t_list	rooms;
	t_list	links;

	ft_bzero(&rooms, sizeof(t_list));
	ft_bzero(&links, sizeof(t_list));
	if (lem_parsing(&rooms, &links, &nb_ants) == -1)
		return (-1);
	return (0);
}
