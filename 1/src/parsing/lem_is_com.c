/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_is_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 21:25:02 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/09 22:57:11 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		lem_is_com(char *line)
{
	if (!line)
		return (-1);
	if (!ft_strncmp(line, "##end", 6))
		return (END);
	if (!ft_strncmp(line, "##start", 8))
		return (START);
	if (line[0] == '#')
		return (COM);
	return (NOT_COM);
}
