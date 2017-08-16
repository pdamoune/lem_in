/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:16:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/06 12:03:14 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Checks for an alphanumeric character
*/

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
