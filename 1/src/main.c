/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:41:26 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/23 11:42:16 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>

int		main(void)
{
	t_data	data;

	if (lem_parsing(&data) == -1)
		return (-1);
	return (0);
}
