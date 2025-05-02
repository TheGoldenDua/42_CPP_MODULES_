NAME = Harl_2.0

SRC = main.cpp Harl.cpp

OBJ = ${SRC:.cpp=.o}

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror 

all : ${NAME}

${NAME} : ${OBJ}
	c++ ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all