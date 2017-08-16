/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:37:55 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/19 09:16:35 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Converts the initial portion of the string pointed to by str to int.
*/

long	ft_atol(const char *str)
{
	int		n;
	int		s;
	long	strnb;

	n = 0;
	s = 0;
	strnb = 0;
	while (ft_isspace(str[n]) == 1)
		n++;
	if (str[n] == '-')
		s = 1;
	if (str[n] == '+' || str[n] == '-')
		n++;
	while (ft_isdigit(str[n]) == 1)
		strnb = (strnb * 10) + (str[n++] - '0');
	if (s == 1)
		return (-strnb);
	return (strnb);
}
