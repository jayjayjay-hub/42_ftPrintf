NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft
INCLUDE = include
SRCS = ft_printf.c\
		output.c\
		print_ptr.c\
		print_hex.c\
		unsigned_itoa.c
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ${INCLUDE}

all: ${NAME}

${NAME}: ${OBJS}
	make all -C ${LIBFTDIR}
	cp ${LIBFTDIR}/${LIBFTNAME} .
	mv ${LIBFTNAME} $(NAME)
	${LIBC} ${NAME} ${OBJS}

clean:
	make clean -C ${LIBFTDIR}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBFTDIR}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
