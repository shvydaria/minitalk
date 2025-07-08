SRCS	= ft_printf.c ft_printf_char.c ft_printf_str.c ft_printf_num_s.c ft_printf_num_u.c ft_printf_hex.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror -I../libft

all:		${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $?

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:  
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
