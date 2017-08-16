/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:31:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/08 19:33:43 by pdamoune         ###   ########.fr       */
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

char		**ft_strcsplit(const char *str, char c)
{
	char	**tab;
	char	*tmp;
	int		i;
	int		j;
	int		words;

	if (!(tmp = ft_strdup(str)))
		return (NULL);
	words = ft_count_c_words(tmp, c);
	tab = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	i = 0;
	j = 0;
	tab[words + 1] = NULL;
	while (tmp[i])
	{
		while (tmp[i] && tmp[i] != c)
			i++;
		tab[j] = ft_strdup(tmp);
		free(tmp);
		if (str[i])
			tmp = ft_strdup(&str[i + 1]);
		j++;
	}
	free(tmp);
	return (tab);
}
