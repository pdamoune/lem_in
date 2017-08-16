/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:52:24 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:51 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Compare lexicographiquement s1 et s2. Si les deux chaines
** sont égales, la fonction retourne 1, ou 0 sinon
*/

int		ft_strdift(const char *str1, const char *str2)
{
	if (*str1 == 0 || *str2 == 0)
		return (1);
	while (str1 && str2)
	{
		if (ft_isalpha(*str1) && ft_isalpha(*str2))
			return (0);
		str1++;
		str2++;
		if (*str1 == 0 || *str2 == 0)
			return (1);
	}
	return (0);
}
