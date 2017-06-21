/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:51:04 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 19:49:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void 	lem_display_data(t_list *data)
{
	ft_printf("%5c===== DATA =====\n", 0);
	while (data)
	{
		ft_printf("%8c%s\n", 0, data->content);
		data = data->next;
	}
	ft_printf("%5c=== FIN DATA ===\n", 0);
}

void 	lem_display(int i, ...)
{
	va_list	ap;
	t_data	*data;
	char	*disp;

	data = v_data();
	va_start(ap, i);
	ft_printf("======== DISPLAY ========\n");
	while (i--)
	{
		disp = va_arg(ap, char *);
		!ft_strcmp(disp, "data") ? lem_display_data(data->list_data) : 0 ;
		!ft_strcmp(disp, "ants") ? ft_printf("%5c===== ANTS =====\n%8ants = %d\n%5c=== FIN ANTS ===\n", 0, data->ants, 0) : 0 ;
	}
	ft_printf("====== FIN DISPLAY ======\n");

}
