# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 22:40:04 by pdamoune          #+#    #+#              #
#    Updated: 2017/06/19 19:37:55 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../lem_in
SOURCES	=	$(PATHLIB)/libft.a \
			src/main.c \
			src/parser.c \
			src/tools.c \
			src/parser/lem_get_data.c \
			src/parser/lem_get_ants.c \
			src/parser/lem_is_com.c \
			src/tools/lem_display.c \
			src/tools/lem_error.c

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
		valgrind $(NAME) < exemple

lib:
		@rm -rf libft
		@ln -s ~/Documents/42/projets_42/library libft
		# git submodule update --init 1/libft

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
