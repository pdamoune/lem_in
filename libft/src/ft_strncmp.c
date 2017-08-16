/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:33:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/10 17:00:09 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Compares at most the first n bytes of str1 and str2
*/

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (!str1 || !str2)
		return ((unsigned char)*str1 - (unsigned char)*str2);
	while ((*str1 && *str2 && i < n
		&& (unsigned char)str1[i] == (unsigned char)str2[i]))
		i++;
	if (i == n)
		return ((unsigned char)str1[i - 1] - (unsigned char)str2[i - 1]);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
