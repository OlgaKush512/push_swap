
SRCS	=		check_args.c fonctions_arr.c fonctions_list_int.c ft_itoa.c			\
				instructions.c math.c algos.c fonctions_list.c fonctions_main.c		\
				main.c putnbr_bin.c which_algo.c ft_atoi.c	fonctions_delete.c		\
				instructions_swap.c	which_algo_four_five.c							\

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC 	= gcc

RM	= rm -f

CFLAGS	=  -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re