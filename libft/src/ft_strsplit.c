/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:31:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/08 19:29:51 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Alloue (avec malloc(3)) et retourne un tableau de chaines de
** caractères “fraiches” (toutes terminées par un ’\0’, le tableau
** également donc) résultant de la découpe de s selon le caractère
** c. Si l’allocation echoue, la fonction retourne NULL. Exemple :
** ft_strsplit("*salut*les***etudiants*", ’*’) renvoie
** le tableau ["salut", "les", "etudiants"].
*/

char		**ft_strsplit(const char *str, char c)
{
	char	**tab;
	char	*tmp;
	int		i;
	int		words;

	if (!(tmp = ft_strctrim(str, c)))
		return (NULL);
	words = ft_count_c_words(tmp, c) - 1;
	tab = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	i = ft_strlen(tmp);
	tab[words + 1] = NULL;
	while (i != 0 && words >= 0)
	{
		while (i != -1 && tmp[i] != c)
			i--;
		tab[words] = ft_strdup(&(((char *)tmp)[i + 1]));
		while (i != -1 && tmp[i] == c)
			i--;
		tmp[i + 1] = '\0';
		words--;
	}
	free(tmp);
	return (tab);
}
