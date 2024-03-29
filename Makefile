# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 22:40:04 by pdamoune          #+#    #+#              #
#    Updated: 2017/08/16 18:16:08 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in
PATHLIB	=	libft
SOURCES	=	src/main.c \
			$(PATHLIB)/libft.a \
			src/tools/lem_error.c \
			src/tools/lem_set_globales.c \
			src/lem_parser.c \
			src/parser/lem_get_data.c \
			src/parser/lem_get_ants.c \
			src/parser/lem_get_rooms.c \
			src/parser/lem_is_com.c \
			src/parser/lem_is_room.c \
			src/parser/lem_is_link.c \
			src/lem_solver.c \
			src/solver/lem_get_paths.c \
			src/solver/lem_get_start.c \
			src/solver/lem_get_end.c \
			src/solver/lem_set_weight.c \
			src/solver/lem_clr_path.c \
			src/solver/lem_busy_path.c \
			src/solver/lem_is_busy.c \
			src/solver/lem_is_possible.c \
			src/solver/lem_multiple_paths.c \
			src/solver/lem_lenmulti.c \
			src/solver/lem_set_paths.c \
			src/lem_display.c \
			src/display/lem_set_visual.c \
			src/display/lem_display_rooms.c \
			src/display/lem_display_multiple.c \
			src/display/lem_display_visual.c \
			src/display/lem_display_move.c
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3
NOFLAGS =	-Wno-format
CC		=	gcc
PATHINC	=	include

all: $(NAME)

$(NAME): library
		@$(CC) -o $(NAME) $(SOURCES) $(CFLAGS)

lib:
		@rm -rf libft
		@ln -s ~/Documents/42/projets_42/library libft

library:
		@make -C $(PATHLIB)

clean:
		@rm -rf $(PATHOBJ)
		@make clean -C $(PATHLIB)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(PATHLIB)

re: fclean all

.PHONY: lib, library, clean, fclean, re, all
