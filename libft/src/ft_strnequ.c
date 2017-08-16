/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:00:25 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:12:33 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Compare lexicographiquement s1 et s2 jusqu’à n caractères
** maximum ou bien qu’un ’\0’ ait été rencontré. Si les deux
** chaines sont égales, la fonction retourne 1, ou 0 sinon.
*/

int	ft_strnequ(const char *str1, const char *str2, size_t n)
{
	if (!(str1 && str2))
		return (0);
	while ((*str1 || *str2) && n)
	{
		if (*str1++ != *str2++)
			return (0);
		n--;
	}
	return (1);
}
