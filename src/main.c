/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 17:03:41 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		usage_h(void)
{
	ft_printf("Usage: lem_in [-h] | [-v] [mode]\n\n");
	ft_printf("%Modes :\n", 0);
	ft_printf("%5ch     Help\n", '-');
	ft_printf("%5cv     Displays\n", '-');
	ft_printf("%5cvd    Debug\n", '-');
	ft_printf("%5cvs    Single, move one ant per turn\n", '-');
	ft_printf("%5cvl    Line, move all the ants per line\n", '-');
	ft_printf("%5cvS    Automatic single, move one ant per second\n", '-');
	ft_printf("%5cvL    Automatic line, move one line per second\n", '-');
	return (0);
}

int		usage_help(int visual, char *argv)
{
	if (ft_strncmp(argv, "-v", 2))
		return (0);
	!ft_strcmp(&argv[2], "") ? visual = VISUAL : 0;
	!ft_strcmp(&argv[2], "s") ? visual = SINGLE : 0;
	!ft_strcmp(&argv[2], "S") ? visual = AUTO_SINGLE : 0;
	!ft_strcmp(&argv[2], "l") ? visual = LINE : 0;
	!ft_strcmp(&argv[2], "L") ? visual = AUTO_LINE : 0;
	!ft_strcmp(&argv[2], "d") ? visual = DEBUG : 0;
	if (!visual)
		return (0);
	return (visual);
}

int		main(int argc, char **argv)
{
	int		visual;

	visual = 0;
	if (argc > 1)
		if (!(visual = usage_help(visual, argv[1])) || argc > 2)
			return (usage_h());
	lem_set_globales();
	lem_parser();
	lem_solver();
	lem_display(visual);
	lem_free(0);
	return (0);
}
