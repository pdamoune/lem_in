/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 11:25:19 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/16 16:54:41 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <fcntl.h>
# include "../libft/include/libft.h"
# include "lem_error.h"
# define NOT_COM		0
# define COM			1
# define START			2
# define END			3
# define VISUAL			1
# define SINGLE			2
# define AUTO_SINGLE	3
# define LINE			4
# define AUTO_LINE		5
# define DEBUG			6
# define CLEAR			"\033\143"

typedef struct s_room	t_room;
typedef struct s_visu	t_visu;

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

struct	s_visu
{
	int		ant;
	int		room_nb;
	char	*room;
	t_room	*cur_room;
	t_room	*prev_room;
	t_list	*multiple;
};

t_list		*g_data;
t_list		*g_rooms;
t_list		*g_paths;
t_list		*g_multiple_paths;
t_list		*g_ants_paths;
t_list		*g_visu;
t_list		*g_tmp;
unsigned int	*g_ants_end;
int			g_ants;
int			g_nb_rooms;

int		main(int argc, char **argv);
void	lem_set_globales(void);
void	lem_free(int err);

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
void	lem_set_weight(void);
void	lem_clr_path(t_list *path);
void	lem_busy_path(t_list *path);
int		lem_is_busy(t_list *path);
int		lem_is_possible(t_list *path, int rayon);
int		lem_multiple_paths(t_list **multiple, t_list *paths, int len);
int		lem_lenmulti(t_list *multi);
void	lem_set_paths(int ants);

/*
** Displayer.
*/

void	lem_display(int bonus);
void	lem_set_visual(t_list *l_ats, t_list *path, t_room *room, t_room *next);
void	lem_display_rooms(t_list *rooms);
void	lem_display_multiple(t_list *multiple);
void	lem_display_visual(int visual, t_list *visu, t_list *tmp, t_visu *ant);
void	lem_display_move(t_visu *visu);

/*
** Display.
*/

#endif
