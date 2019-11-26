# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 19:48:26 by oelazzou          #+#    #+#              #
#    Updated: 2019/11/12 20:19:51 by oelazzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC 	 = gcc
CFLAGS =  -Wall -Werror -Wextra
SRC =  src/ft_check.c src/main.c src/draw_line.c src/key.c src/rotation.c src/free.c src/ft_error.c src/inc_value.c src/menu.c
OBJ = $(SRC:%.c=%.o)
LIBF = libft/libft.a

all:$(NAME)

$(NAME): $(OBJ)
	@make -C libft 
	@echo "\033[92mmake libft"
	@echo "\033[92mdone!\033[0m"
	$(CC) $(CFLAGS) $(OBJ) -I /usr/local/include -I src/fdf.h -L /usr/local/lib -lmlx -L libft/ -lft  -framework OpenGL -framework AppKit $(LIBF) -o $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "cleaning..."
	@make clean -C ./libft
	rm -rf $(OBJ)
	@echo "\033[92mlibft object files removed!\033[0m"
fclean: clean
	@rm -rf $(NAME)
	@echo "\033[92mFDF executable removed!\033[0m"
	@make fclean -C ./libft 
	@echo "\033[92mdone!\033[0m"

re: fclean all
	make re -C libft/
