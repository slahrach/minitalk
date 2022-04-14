NAME =

SERVER = server

CLIENT = client

SRCS1 = server.c ft_itoa.c utils.c 

SRCS2 = client.c ft_itoa.c utils.c

OBJ1 = ${SRCS1:.c=.o}

OBJ2 = ${SRCS2:.c=.o}

CFLAGS =  -Wall -Wextra -Werror

${NAME} : all

all : ${SERVER} ${CLIENT}

${SERVER} : ${OBJ1}
		${CC} ${OBJ1} -o ${SERVER}

${CLIENT} : ${OBJ2}
		${CC} ${OBJ2} -o ${CLIENT}

clean :
		rm -f ${OBJ1} ${OBJ2}

fclean : clean
		rm -f ${CLIENT} ${SERVER}

re : fclean all

%.o : %.c
		${CC} ${CFLAGS} -c $<

.PHONY : clean fclean re

