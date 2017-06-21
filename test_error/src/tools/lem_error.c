/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:50:57 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 19:27:05 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void 	lem_error(int err)
{
	err == EMPTY_FILE ? ft_printf("GNL - > File empty\n") : 0;
	err == GNL_ERROR ? ft_printf("GNL - > File error\n") : 0;
}
