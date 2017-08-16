/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:39:08 by pdamoune          #+#    #+#             */
/*   Updated: 2017/03/06 12:03:45 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** checks whether c is a 7-bit unsigned char value that fits into the ASCII
** character set.
*/

int		ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
