# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 22:40:04 by pdamoune          #+#    #+#              #
#    Updated: 2017/05/15 11:01:12 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../lem_in
SOURCES	=	src/main.c \
			$(PATHLIB)/libft.a \
			src/lem_parsing.c
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
		./$(NAME) < exemple

seg:	$(NAME)
		./$(NAME) < segfault

val:	$(NAME)
		valgrind $(NAME) < exemple

visu: visuel run

visuel:
	osascript -e 'tell application "iTerm" to activate' -e \
	'tell application "System Events" to tell process "iTerm" \
	to keystroke "n" using {command down}'
	@# @osascript -e 'tell application "iTerm" to activate' -e \
	@# 'tell application "System Events" to tell process "iTerm" \
	@# to keystroke "d" using {command down}'
	osascript -e 'tell application "iTerm" to activate' -e \
	'tell application "System Events" to tell process "iTerm" \
	to keystroke "n" using {command down}'
	@#, shift down}'

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
