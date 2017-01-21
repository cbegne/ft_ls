# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbegne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 16:45:33 by cbegne            #+#    #+#              #
#    Updated: 2017/01/21 17:37:31 by cbegne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS_NAME =	main.c\
			get_option.c\
			get_stat.c\
			get_stat2.c\
			error.c\
			form_tree.c
SRCS_PATH =	srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = obj/
OBJ	= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME = ft_ls
FLAGS =	-Wall -Werror -Wextra
INC	= -I./includes/


.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(OBJ) $(INC) -L ./libft/ -lft -o $(NAME)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< $(INC) -o $@

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
