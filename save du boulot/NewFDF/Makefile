# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 15:25:18 by vgauther          #+#    #+#              #
#    Updated: 2017/12/19 12:22:05 by vgauther         ###   ########.fr        #
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
SRC = main.c ft_open_n_read.c GNL/get_next_line.c ft_bresenham.c ft_open_map.c ft_print_map.c
FLAGS = -Werror -Wall -Wextra
FWORK = -framework OpenGL -framework AppKit

.PHONY: clean fclean re re-bis all

all:$(NAME)

$(NAME):
	@echo "$(RESET)$(CYAN)MAKING LIBFT ...$(RESET)"
	@make -C libft/
	@echo "$(RESET)$(CYAN)MAKING MLX LIB ...$(RESET)"
	@make -C minilibx_macos/
	@gcc -o $(NAME) $(FLAGS) $(FWORK) $(SRC) \
		-I ./minilibx_macos -L ./minilibx_macos -l mlx -I ./libft \
		-L ./libft -l ft
	@echo "$(RESET)$(GREEN)EXECUTABLE FDF DONE$(RESET)"


clean:
	@echo "$(RESET)$(RED)DELETING LIBFT..$(RESET)"
	@make -C libft/ clean
	@echo "$(RESET)$(GREEN)LIBFT DELETED$(RESET)"
	@echo "$(RESET)$(RED)DELETING MLX..$(RESET)"
	@make -C minilibx_macos/ clean
	@echo "$(RESET)$(GREEN)MLX DELETED$(RESET)"
	@rm -f $(NAME)

fclean:clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(RESET)$(GREEN)ALL FCLEANED$(RESET)"

re:fclean all

re-bis:
	@gcc -o $(NAME) $(FLAGS) $(FWORK) $(SRC) -I minilibx_macos/ -I libft/
	@echo "$(RESET)$(GREEN)EXECUTABLE FDF DONE$(RESET)"

