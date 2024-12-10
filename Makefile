# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 12:29:55 by mkoyamba          #+#    #+#              #
#    Updated: 2024/11/30 14:14:42 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = lem-in
CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I include/lem-in.h
LIB = lib/libft/libft.a

#          ----------========== {     SRCS     } ==========----------

SRC = main.c\

# parsing
SRC +=\
	file.c\
	free_data.c\
	gathering_data.c\
	links.c\
	parsing_tools.c\
	parsing.c\
	print.c\
	split_file.c\

# exec
SRC +=\
	exec.c\

#          ----------========== {     OBJS     } ==========----------

SRC_DIR = src/
OBJ_DIR = src/obj_dir/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

VPATH= $(shell find ./ -type d)

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C lib/libft
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@printf "\e[1;42m \e[0;m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -C lib/libft clean
	@rm -f $(OBJ)
	@rm -rf src/obj_dir
	@printf "\e[0;31m[.o files deleted]\n\e[0;m"

fclean: clean
	@make -C lib/libft fclean
	@rm -f $(NAME)
	@printf "\e[0;31m[$(NAME) deleted]\n\e[0;m"

re: fclean all

.PHONY: all clean fclean re bonus