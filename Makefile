# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkael <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 12:11:53 by bkael             #+#    #+#              #
#    Updated: 2021/08/13 19:00:30 by bkael            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FRAEMWORKS = -framework OpenGL -framework AppKit

MLX = mlx/libmlx.a

SRC = sources/camera.c \
	sources/color.c \
	sources/controls.c \
	sources/drawing.c \
	sources/main.c \
	sources/set_map.c \
	utils/get_next_line/get_next_line.c \
	utils/get_next_line/get_next_line_utils.c \
	utils/utils1.c \
	utils/utils2.c \
	utils/utils3.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx/
	gcc $(FLAGS) $^ $(MLX) $(FRAEMWORKS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@make -C mlx/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
