SRCS	= client.c server.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= minitalk

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -Ift_printf -c $? -o $@

${NAME}:	 server client

server:		server.o
		@make -C libft
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o server

client:		client.o
		@make -C libft
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o client

libft:
		make -C libft

ft_printf:
		make -C ft_printf

clean:
			make clean -C libft
			make clean -C ft_printf
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY:		libft ft_printf
