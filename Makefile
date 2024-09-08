# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 11:36:16 by mde-maga          #+#    #+#              #
#    Updated: 2024/09/07 12:01:06 by mde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c ft_utility.c ft_map_parser.c ft_map_init.c ft_error.c ft_flood.c \
	ft_textures.c ft_movement.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L. -lXext -L. -lX11

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./libs/mlx_linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(MINILIBX):
	@make -s -C $(MINILIBX_PATH)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all