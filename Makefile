# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 17:50:00 by mazeghou          #+#    #+#              #
#    Updated: 2024/12/24 00:07:27 by mazeghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = include/minilibx-linux
LIBFT_DIR = include/libft
INCLUDE_DIR = include

MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBS = -L$(MLX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -lft -lm -lXext -lX11
SCR_DIR = src
GET_NEXT_LINE_DIR = include/get_next_line

SRCS = $(SCR_DIR)/main.c \
$(SCR_DIR)/utils/map/check_map.c \
$(GET_NEXT_LINE_DIR)/get_next_line.c \
$(GET_NEXT_LINE_DIR)/get_next_line_utils.c \
$(SCR_DIR)/utils/map/fill_map.c \
$(SCR_DIR)/utils/player/move_player.c \
$(SCR_DIR)/utils/map/check_path.c \
$(SCR_DIR)/utils/map/check_elements.c \
$(SCR_DIR)/utils/map/map_reader.c \
$(SCR_DIR)/utils/handlers.c \
$(SCR_DIR)/utils/score.c \
$(SCR_DIR)/utils/enemy/enemy.c \
$(SCR_DIR)/utils/render.c \
$(SCR_DIR)/utils/init.c \
$(SCR_DIR)/utils/window.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I$(INCLUDE_DIR) -o $(NAME)

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
