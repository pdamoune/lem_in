# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 22:40:04 by pdamoune          #+#    #+#              #
#    Updated: 2017/07/20 18:12:57 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../lem_in
SOURCES	=	src/main.c \
			$(PATHLIB)/libft.a \
			src/tools/lem_error.c \
			src/tools/lem_display.c \
			src/tools/lem_set_globales.c \
			src/lem_parser.c \
			src/parser/lem_get_data.c \
			src/parser/lem_get_ants.c \
			src/parser/lem_get_rooms.c \
			src/parser/lem_is_com.c \
			src/parser/lem_is_room.c \
			src/parser/lem_is_link.c \
			src/lem_solver.c \
			src/solver/lem_get_start.c \
			src/solver/lem_get_paths.c
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3
NOFLAGS =	-Wno-format
CC		=	gcc
PATHLIB	=	libft
PATHINC	=	include

all: $(NAME)

$(NAME): library
		@$(CC) -o $(NAME) $(SOURCES) $(CFLAGS) $(DEBUG)

run:	$(NAME)
		./$(NAME) < ../data

seg:	$(NAME)
		./$(NAME) < segfault

val:	$(NAME)
		valgrind ./$(NAME) < ../data

lib:
		@rm -rf libft
		@ln -s ~/Documents/42/projets_42/library libft

library: lib
		@make -C $(PATHLIB)

clean:
		@rm -rf $(PATHOBJ)
		@make clean -C $(PATHLIB)

fclean: clean
		@rm -f $(NAME)
		make fclean -C $(PATHLIB)

re: fclean all

.PHONY: lib, library, clean, fclean, re, all
