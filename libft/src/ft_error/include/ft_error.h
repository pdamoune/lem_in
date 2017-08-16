/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:40:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/10 14:22:20 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <errno.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_error(int code, ...);

#endif
