/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:29:50 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/21 20:59:12 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 100
# include "../../include/libft.h"
# include <fcntl.h>

int			get_next_line(const int fd, char **line);

#endif
