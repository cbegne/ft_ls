# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbegne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 16:45:33 by cbegne            #+#    #+#              #
#    Updated: 2017/02/15 12:50:30 by cbegne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		get_option.c\
		get_stat.c\
		get_stat2.c\
		error.c\
		form_tree.c\
		form_dir_tree.c\
		print_tree.c\
		print_dir_tree.c\
		get_print_padding.c\
		free_nodes.c
OBJ = $(SRCS:.c=.o)
NAME = ft_ls
FLAGS =	-Wall -Werror -Wextra
INC	= includes/

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -I $(INC) -L ./libft/ -lft -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	gcc -c $(FLAGS) -I $(INC) -o $@ $<

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
