# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 17:50:00 by mazeghou          #+#    #+#              #
#    Updated: 2025/01/06 15:16:22 by mazeghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = include/minilibx-linux
LIBFT_DIR = include/libft
GET_NEXT_LINE_DIR = include/get_next_line
INCLUDE_DIR = include

MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBS = -L$(MLX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -lft -lm -lXext -lX11

INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(GET_NEXT_LINE_DIR)

SRCS = src/main.c \
       src/utils/map/check_map.c \
       src/utils/map/check_path.c \
       src/utils/map/map_utils.c \
       src/utils/map/map_reader.c \
       src/utils/map/fill_map.c \
       src/utils/map/check_elements.c \
       src/utils/player/move_player.c \
       src/utils/enemy/enemy.c \
       src/utils/enemy/enemy_placement.c \
       src/utils/enemy/enemy_validation.c \
       src/utils/enemy/enemy_map.c \
       src/utils/enemy/enemy_path.c \
       src/utils/handlers.c \
       src/utils/score.c \
       src/utils/render.c \
       src/utils/init.c \
       src/utils/window.c \
       include/get_next_line/get_next_line.c \
       include/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -o $(NAME) $(LIBS)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
