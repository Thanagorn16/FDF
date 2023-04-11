# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 13:29:28 by truangsi          #+#    #+#              #
#    Updated: 2023/04/11 15:09:10 by truangsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework Appkit

NAME = fdf

LIBFT_PATH = libft/

GNL_PATH = get_next_line/

MLX_PATH = mlx/

LIBFT_SRCS = ft_strlen.c ft_split.c ft_atoi.c

GNL_SRCS = get_next_line.c get_next_line_utils.c

FDF_SRCS = fdf.c create_node.c render.c

SRCS = $(FDF_SRCS) \
						$(addprefix $(LIBFT_PATH), $(LIBFT_SRCS)) \
						$(addprefix $(GNL_PATH), $(GNL_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	gcc $(OBJS) $(FLAGS) $(MLX_FLAG) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus