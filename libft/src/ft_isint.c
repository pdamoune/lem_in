/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 11:18:30 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 17:41:56 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_isint(const char *nbr)
{
	int i;
	int	sign;

	if (!nbr)
		return (0);
	while (!ft_isdigit(*nbr) && ft_isspace(*nbr))
		nbr++;
	sign = (((nbr[0] == '-') || (nbr[0] == '+')) ? 1 : 0);
	i = sign;
	while (nbr[i])
	{
		if (i > 9 + sign)
			return (0);
		if (i == 9 + sign)
			if ((!sign && ft_strcmp(nbr, "2147483647") > 0)
			|| (nbr[0] == '-' && ft_strcmp(nbr, "-2147483648") > 0))
				return (0);
		if (!ft_isdigit(nbr[i]))
			break ;
		i++;
	}
	return (1);
}
