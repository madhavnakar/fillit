# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnakar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 20:14:02 by mnakar            #+#    #+#              #
#    Updated: 2018/06/29 18:38:57 by mnakar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

FILES = main.c valid.c parse.c examine.c solve.c solver.c 

LIBFT = libft/

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME) :
	make -C $(LIBFT)
	gcc $(CFLAGS) -c $(FILES) 
	gcc $(OBJ) -o $(NAME) -L$(LIBFT) -lft

clean:
	make clean -C $(LIBFT)
	rm -f *.o

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
