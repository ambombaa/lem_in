# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:11:45 by ambombaa          #+#    #+#              #
#    Updated: 2018/08/30 16:11:49 by ambombaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIBF = libft/
GNL = gnl/get_next_line.c

SRCS =	src/add_rooms.c \
		src/create_tab.c \
		src/free_array.c \
		src/links.c \
		src/main.c \
		src/print_result.c \
		src/rooms.c \
		src/solution.c \
		src/initialise.c \
		src/integration.c \
		src/path.c \
		src/display.c \
		src/moves.c

CCFL = -Wall -Wextra -Werror -L $(LIBF) -lft

all: $(NAME)

$(NAME):
		@make -C $(LIBF) re
		@gcc $(CCFL) $(SRCS) $(GNL) -o $(NAME)

clean:
		@make -C $(LIBF) clean

fclean:
		@make -C $(LIBF) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
