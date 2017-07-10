/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:23:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/10 19:33:57 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void 	lem_disp_data(t_list *data)
{
	if (!data)
		return ;
	ft_printf("%2cDATA\n---------------------\n", 0);
	while (data)
	{
		ft_printf("%s\n", data->content);
		data = data->next;
	}
	ft_printf("=====================\n");
}

void 	lem_display(int args, ...)
{
	va_list		ap;
	char		*arg;

	ft_printf("\n================= DISPLAY =================\n");
	va_start(ap, args);
	while (args--)
	{
		arg = va_arg(ap, char *);
		if (!ft_strcmp("ants", arg))
			ft_printf("%2cANTS = %d\n=====================\n", 0, g_ants);
		if (!ft_strcmp("data", arg))
			lem_disp_data(g_data);
	}
	ft_printf("=============== FIN DISPLAY =================\n\n");
}
