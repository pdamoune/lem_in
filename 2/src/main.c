/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/24 15:47:10 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		main(void)
{
	lem_set_globales();
	lem_parser();
	lem_solver();
	// lem_display(1, "paths");
	lem_free(0);
	return (0);
}
