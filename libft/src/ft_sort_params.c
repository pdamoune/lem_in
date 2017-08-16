/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:14:17 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:14 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Affiche les arguments reçus en ligne de commande.
*/

void	ft_sort_params(int argc, char **argv)
{
	int	n;

	n = 1;
	while (n + 1 < argc)
	{
		if (ft_strcmp(argv[n], argv[n + 1]) > 0)
		{
			ft_swap((int *)&(argv[n]), (int *)&(argv[n + 1]));
			n = 1;
		}
		n++;
	}
}
