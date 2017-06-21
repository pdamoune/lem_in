/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:54:46 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 15:03:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/lem_in.h"

void 	display(void *content)
{
	ft_putendl((char *)content);
}

void	lem_error(t_error *error)
{
	t_data		*data;

	data = lem_data();

	error->gnl == 0 ? ft_printf("GNL - > File empty\n") : 0;
	error->gnl == -1 ? ft_printf("GNL - > File error\n") : 0;
	error->ants == 0 ? ft_printf("ANTS - > No ants\n") : 0;
	error->ants == -1 ? ft_printf("ANTS - > Ants number is not an int\n") : 0;
	error->ants == -2 ? ft_printf("ANTS - > Ants number is negative\n") : 0;
	error->rooms == 2 ? ft_printf("ROOMS - > No START room\n") : 0;
	error->rooms == 1 ? ft_printf("ROOMS - > No END room\n") : 0;
	error->rooms == 0 ? ft_printf("ROOMS - > No END and START room\n") : 0;
	error->rooms == -1 ? ft_printf("ROOMS - > Multiple STARTS\n") : 0;
	error->rooms == -2 ? ft_printf("ROOMS - > Multiple ENDS\n") : 0;
	error->rooms == -3 ? ft_printf("ROOMS - > The line is not valid\n") : 0;
	error->links == 0 ? ft_printf("LINKS - > problem links\n") : 0;
	ft_lstforeach((t_list *)data->list_rooms, &display);
	exit (0);
}
