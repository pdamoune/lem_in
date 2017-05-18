/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:42:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/18 04:19:05 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/include/libft.h"
# define START	1
# define END	2

typedef struct s_room	t_room;
typedef struct s_link	t_link;

struct		s_room
{
	char	*name;
	int		x;
	int		y;
	int		pos[3];
};

struct		s_link
{
	char	*room1;
	char	*room2;
};


int		main(void);
int		lem_parsing(t_list *rooms, t_list *links, int *nb_ants);

#endif
