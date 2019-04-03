# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ayundina <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/07 10:20:15 by ayundina      #+#    #+#                  #
#    Updated: 2019/03/07 10:24:12 by ayundina      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = main.o check_ttr.o crt_ttr_arr.o libft.o go_sqr.o fillit.o only_nl.o

SRC = main.c check_ttr.c crt_ttr_arr.c libft.c go_sqr.c fillit.c only_nl.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o main.o -c main.c
	gcc -Wall -Wextra -Werror -o check_ttr.o -c check_ttr.c
	gcc -Wall -Wextra -Werror -o crt_ttr_arr.o -c crt_ttr_arr.c
	gcc -Wall -Wextra -Werror -o libft.o -c libft.c
	gcc -Wall -Wextra -Werror -o go_sqr.o -c go_sqr.c
	gcc -Wall -Wextra -Werror -o fillit.o -c fillit.c
	gcc -Wall -Wextra -Werror -o only_nl.o -c only_nl.c
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I.

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

