/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 23:01:33 by philippe          #+#    #+#             */
/*   Updated: 2017/04/02 23:15:01 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Converts the letter c to upper case, if possible.
*/

void	ft_strtoupper(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
}
