/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:18:18 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/02 16:25:35 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Compares the two strings s1 and s2. It returns an integer less than, equal
** to, or greater than zero if s1 is found, respectively, to be less than, to
** match, or be greater than s2.
*/

int		ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
		str1++ && str2++;
	return (*str1 - *str2);
}
