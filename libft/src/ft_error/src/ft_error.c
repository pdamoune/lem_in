/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:39:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 13:38:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_error.h"

/*
** int args = nombre d arguments en plus des 3 de base.
** ... = file, function, line
** ... =
*/
#include <fcntl.h>

int		ft_error(int args, ...)
{
	va_list		ap;
	void		(*f)(int);
	int			fd;
	int			err;

	va_start(ap, args);
	err = va_arg(ap, int);
	fd = 2;
	ft_printf("%@\n===================================================\n", fd);
	ft_printf("%@|{red}ERROR :{eoc}\n", fd);
	ft_printf("%@|{mag}   File{eoc}     : %s\n", fd, va_arg(ap, char *));
	ft_printf("%@|{cya}   Function{eoc} : %s\n", fd, va_arg(ap, char *));
	ft_printf("%@|{yel}   Line{eoc}     : %d\n", fd, va_arg(ap, int));
	ft_printf("%@===================================================\n\n", fd);
	while (args--)
	{
		ft_printf("%@{red}erreur :{eoc}\n", fd);
		ft_printf("%@%5c%s\n", fd, 0, va_arg(ap, char *));
	}
	f = va_arg(ap, void *);
	f(err);
	va_end(ap);
	return (-1);
}
