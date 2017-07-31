/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:19 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/28 15:22:23 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/include/libft.h"
# include "lem_error.h"
# define NOT_COM		0
# define COM			1
# define START			2
# define END			3

typedef struct s_room	t_room;
typedef struct s_link	t_link;

struct	s_room
{
	char	*name;
	int		room_number;
	int		position;
	int		busy;
	int		weight;
	int		coor[2];
	t_list	*links;
};

t_list	*g_data;
t_list	*g_rooms;
t_list	*g_paths;
t_list	*g_multiple_paths;
int		g_ants;
int		g_nb_rooms;

void	lem_set_globales(void);
void 	lem_display(int args, ...);
void	lem_free(int err);
int		main(void);

/*
** Parser.
*/

int		lem_parser(void);
int		lem_get_data(void);
int		lem_get_ants(t_list *data);
int		lem_get_rooms(void);
int		lem_is_com(char *line);
int		lem_is_room(t_room *room, char *line);
int		lem_is_link(char *line);

/*
** Solver.
*/

int		lem_solver(void);
t_room	*lem_get_start(t_list *rooms);
t_room	*lem_get_end(t_list *rooms);
int		lem_get_paths(void);

#endif
