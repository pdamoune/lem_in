# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 11:25:43 by pdamoune          #+#    #+#              #
#    Updated: 2017/05/15 11:02:22 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem_in
SOURCES	=
CFLAGS	=	-Wall -Wextra -Werror
NOFLAGS =	-Wno-format
CC		=	gcc
PATHLIB	=	1/libft
PATHINC	=	include
PATHPRO	=	1

all: project

project:
		@make -C $(PATHPRO)

run:	project
		./$(NAME) < data

clean:
		@make clean -C $(PATHPRO)

fclean: clean
		make fclean -C $(PATHPRO)

re: fclean all

.PHONY: lib, library, clean, fclean, re, all, $(NOFLAGS), $(NAME)
