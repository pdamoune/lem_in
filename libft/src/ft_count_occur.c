/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:18:55 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/06 11:55:45 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Compte le nombre d occurence du caractere c dans str
*/

int		ft_count_occur(char *str, int c)
{
	int count;

	count = 0;
	while (*str)
		if (*str++ == c)
			count++;
	return (count);
}
