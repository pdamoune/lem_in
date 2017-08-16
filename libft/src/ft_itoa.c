/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:00:11 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:09:57 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères
** “fraiche” terminée par un ’\0’ représentant l’entier n passé
** en paramètre. Les nombres négatifs doivent être gérés. Si l’allocation
** échoue, la fonction renvoie NULL.
*/

static char	*ft_itoaneg(int len, int n, long nb)
{
	char	*str;

	nb = n;
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	while (nb < 0)
	{
		str[len] = -(nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	str[0] = '-';
	return (str);
}

static char	*ft_itoapos(int len, int n, long nb)
{
	char	*str;

	nb = n;
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	len--;
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = 1;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		len++;
	}
	if (n == 0)
		str = ft_strdup("0");
	else if (n < 0)
		str = ft_itoaneg(len, n, nb);
	else
		str = ft_itoapos(len, n, nb);
	return (str);
}
