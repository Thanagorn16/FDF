# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:00:21 by truangsi          #+#    #+#              #
#    Updated: 2023/04/18 15:47:42 by truangsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework Appkit

NAME = fdf

LIBFT_PATH = libft/
LIBFT_FLAG = -Llibft -lmylib
LIBFT_HD = -Ilibft

GNL_PATH = get_next_line/
GNL_FLAG = -get_next_line -lgnl
GNL_HD = -Iget_next_line

MLX_PATH = mlx/

LIBFT_SRCS = ft_strlen.c ft_split.c ft_atoi.c

GNL_SRCS = get_next_line.c get_next_line_utils.c

FDF_SRCS = fdf.c create_node.c render.c calculate.c translate.c utils.c

SRCS = $(FDF_SRCS) \
						$(addprefix $(LIBFT_PATH), $(LIBFT_SRCS)) \
						$(addprefix $(GNL_PATH), $(GNL_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(GNL_PATH)
	@make -C $(MLX_PATH)
	gcc $(OBJS) $(FLAGS) $(MLX_FLAG) -o $(NAME)

clean:
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(GNL_PATH)
	rm -f $(OBJS)

fclean: clean
	@make clean -C $(MLX_PATH)
	rm -f $(NAME)

re: clean all

.PHONY: clean fclean re all bonus