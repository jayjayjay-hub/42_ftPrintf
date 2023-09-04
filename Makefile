NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft
INCLUDE = include
SRCS = ft_printf.c\
		ft_output.c
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ${INCLUDE}
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFTDIR}
	${LIBC} ${NAME} ${LIBFTDIR}/${LIBFTNAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
