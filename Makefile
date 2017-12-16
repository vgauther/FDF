# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 15:25:18 by vgauther          #+#    #+#              #
#    Updated: 2017/12/14 13:52:52 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#COLORS

RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

NAME = fdf
SRC = main.c ft_open_n_read.c GNL/get_next_line.c
FLAGS = -Werror -Wall -Wextra -g
FWORK = -framework OpenGL -framework AppKit

.PHONY: clean fclean re re-bis all

all:$(NAME)

$(NAME):
	@make -C libft/
	@echo "$(RESET)$(CYAN)MAKING MLX LIB ...$(RESET)"
	@make -C minilibx_macos/
	@gcc -o $(NAME) $(FLAGS) $(FWORK) $(SRC) \
		-I minilibx_macos/ -lmlx -I libft/ -L libft/ -lft
	@echo "$(RESET)$(GREEN)EXECUTABLE FDF DONE$(RESET)"


clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@rm -f $(NAME)

fclean:clean
	@make -C libft/ fclean

re:fclean all

re-bis:
	@gcc -o $(NAME) $(FLAGS) $(FWORK) $(SRC) -I minilibx_macos/ -lmlx -I libft/ -L libft/ -lft


