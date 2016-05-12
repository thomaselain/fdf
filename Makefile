# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telain <telain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 17:19:39 by telain            #+#    #+#              #
#    Updated: 2016/05/11 20:09:53 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = src/
PATH_INC = ./libft/includes/

CC = gcc
FLAGS = -Wall -Wextra -Werror

HEAD = includes/fdf.h

SRC =	main.c\
		read_file.c\
		draw_grid.c\
		line.c\
		oct_1.c oct_2.c oct_3.c oct_4.c oct_5.c oct_6.c oct_7.c oct_8.c\

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@printf "Compiling $(NAME) ...\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@printf "\n\n\e[32m"
	@printf "     .______________________________________________________________.\n"
	@printf "     |    _____   _  __                             _ _          _  |\n"
	@printf "     |   |  ___|_| |/ _|   ___ ___  _ __ ___  _ __ (_) | ___  __| | |\n"
	@printf "     |   | |_ / _  | |_   / __/ _ \|  _   _ \|  _ \| | |/ _ \/ _  | |\n"
	@printf "     |   |  _| (_| |  _| | (_| (_) | | | | | | |_) | | |  __/ (_| | |\n"
	@printf "     |   |_|  \____|_|    \___\___/|_| |_| |_| ___/|_|_|\___|\____| |\n"
	@printf "     |                                        |_|                   |\n"
	@printf "     .______________________________________________________________.\n\e[0m"

%.o: %.c
	@$(CC) $(FLAGS) $(HEADERS) -c -o $@ $^
	@printf "[\e[32mfdf object\e[0m]\e[32m--\e[0m--\e[32m--\e[0m> : $@"
	@printf "\e[0m\n"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
