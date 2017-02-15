# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbegne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 14:18:02 by cbegne            #+#    #+#              #
#    Updated: 2017/02/14 19:57:54 by cbegne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS_NAME = ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strlenc.c\
	   ft_strdup.c\
	   ft_strndup.c\
	   ft_strcpy.c\
	   ft_strncpy.c\
	   ft_strcat.c\
	   ft_strncat.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strstr.c\
	   ft_strnstr.c\
	   ft_strcmp.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_isupper.c\
	   ft_isspace.c\
	   ft_islower.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_memalloc.c\
	   ft_memdel.c\
	   ft_strnew.c\
	   ft_strcnew.c\
	   ft_strdel.c\
	   ft_strclr.c\
	   ft_striter.c\
	   ft_striteri.c\
	   ft_strmap.c\
	   ft_strmapi.c\
	   ft_strequ.c\
	   ft_strnequ.c\
	   ft_strsub.c\
	   ft_strjoin.c\
	   ft_strnjoin.c\
	   ft_strnnjoin.c\
	   ft_strtrim.c\
	   ft_strsplit.c\
	   ft_itoa.c\
	   ft_itoa_base.c\
	   ft_putchar.c\
	   ft_putstr.c\
	   ft_putendl.c\
	   ft_putnbr.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_swap.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_lstaddback.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_sqrt.c\
	   ft_abs.c\
	   ft_putwchar.c\
	   ft_putwstr.c\
	   ft_max.c\
	   ft_strupper.c\
	   ft_sort_params.c\
	   get_next_line.c\

SRCS_PATH = ./srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

PRINTF_NAME = ft_printf.c\
		parse.c\
		get_flag_length.c\
		get_width_precision.c\
		get_index.c\
		convert_and_apply.c\
		create_unsigned.c\
		create_signed.c\
		create_char_string.c\
		create_wchar_string.c\
		check_params.c\
		apply_param_unsigned.c\
		apply_param_signed.c\
		apply_param_string.c

PRINTF_PATH = ./ft_printf/
PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_NAME))

OBJ_NAME = $(SRCS_NAME:.c=.o)\
		$(PRINTF_NAME:.c=.o)
OBJ_PATH = ./obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = ./includes/

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
		@mkdir -p obj
		@gcc -c $(FLAGS) $< -I $(INC) -o $@

$(OBJ_PATH)%.o: $(PRINTF_PATH)%.c
		@mkdir -p obj
		@gcc -c $(FLAGS) $< -I $(INC) -o $@

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
