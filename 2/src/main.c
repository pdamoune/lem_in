/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/20 22:40:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		main(void)
{
	lem_set_globales();
	lem_parser();
	lem_solver();
	lem_display(1, "multiple");
	lem_free(0);
	return (0);
}
