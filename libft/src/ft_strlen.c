/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:09:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/20 10:42:48 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Computes the length of the string str up to, but not including the
** terminating null character
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
