/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:42:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/19 19:59:58 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/include/libft.h"
# include "lem_error.h"
# include <stdarg.h>
# define NOT_COM		0
# define COM			1
# define START			2
# define END			3
# define GNL			1
# define BAD_LINE		(1 << 1)
# define BAD_ANTS		(1 << 2)
// # define ERROR

typedef struct s_data	t_data;
typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_path	t_path;

struct		s_data
{
	int			ants;
	int			map[2];
	char		**graph;
	t_list		*list_data;
	t_list		*list_rooms;
	t_list		*list_links;
	t_list		*list_paths;
};

struct		s_room
{
	char	*name;
	int		rm_nb;
	int		pos;
	int		busy;
	long	x;
	long	y;
};

struct		s_link
{
	char	*room1;
	char	*room2;
};

struct		s_path
{
	char	*name;
};


t_data	*v_data(void);
void 	lem_display(int i, ...);
void 	lem_error(int err);
int		main(void);
void	lem_parser(void);
void 	lem_get_data(void);
void 	lem_get_ants(t_list *data);
int		lem_is_com(char *line);


#endif
