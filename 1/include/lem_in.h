/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:42:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/23 15:09:14 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/include/libft.h"
# define NOT_COM		0
# define COM			1
# define START			2
# define END			3
# define BAD_LINE		(1 << 1)
# define BAD_ANTS		(1 << 2)
// # define ERROR

typedef struct s_data	t_data;
typedef struct s_room	t_room;
typedef struct s_link	t_link;

struct		s_data
{
	int		ants;
	int		map[2];
	char	**graph;
	t_list	*list_data;
	t_list	*list_rooms;
	t_list	*list_links;
};

struct		s_room
{
	char	*name;
	long	x;
	long	y;
	int		pos;
};

struct		s_link
{
	char	*room1;
	char	*room2;
};


int		main(void);
int		lem_parsing(t_data *data);

#endif
