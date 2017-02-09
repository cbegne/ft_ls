# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbegne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 16:45:33 by cbegne            #+#    #+#              #
#    Updated: 2017/02/07 16:31:52 by cbegne           ###   ########.fr        #
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
			get_print_padding.c
SRCS_PATH =	srcs/
SRCS_OLD = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(SRCS:.c=.o)
OBJ_PATH = obj/
OBJ_OLD	= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME = ft_ls
FLAGS =	-Wall -Werror -Wextra
INC	= -I./includes/


.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(INC) -L ./libft/ -lft -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< $(INC) -o $@

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
