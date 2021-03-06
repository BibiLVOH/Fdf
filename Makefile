# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 12:44:05 by bvigne            #+#    #+#              #
#    Updated: 2018/03/05 20:57:38 by bvigne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

D_SRCS = ./sources/

SRCS =	main.c			\
		parse.c			\
		convert.c		\
		display.c		\
		bresenham.c		\
		draw.c			\
		key.c			\
		free.c

FLAG = -Wall -Wextra -Werror

MLX_FLG_MAC = -lmlx -framework OpenGL -framework AppKit

LIB = -C ./libft/
OPTION = -c -include fdf.h
OBJ = $(SRCS:.c=.o)

SUCCESS_COLOR = \033[32m

all: $(NAME)

%.o:$(D_SRCS)%.c
	@gcc $(FLAG) -I ./libft -I /includes -o $@ -c $<

$(NAME): $(OBJ)
	@make $(LIB) MAKEFLAGS=s
	@gcc $(FLAG) $(MLX_FLG_MAC) -o $(NAME) $(OBJ) -L./libft -lft
	@echo "$(SUCCESS_COLOR)$(NAME) - Compiled with success"

clean:
	@make clean $(LIB) MAKEFLAGS=s
	@rm -rf $(OBJ)
	@echo "$(SUCCESS_COLOR)$(NAME) - Cleaned with success"

fclean: clean
	@make fclean $(LIB) MAKEFLAGS=s
	@rm -rf $(NAME)
	@echo "$(SUCCESS_COLOR)$(NAME) - Fcleaned with success"

re: fclean all

.PHONY: all clean fclean re
