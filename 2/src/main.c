/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/03 11:59:21 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		main(void)
{
	lem_set_globales();
	lem_parser();
	lem_set_weight();
	lem_solver();
	// lem_display(2, "rooms", "multiple");
	lem_display(1, "multiple");
	// int i = 0;
	// int	j = INT_MAX;
	// while (++i)
	// {
	//
	// }
	lem_free(0);
	return (0);
}
