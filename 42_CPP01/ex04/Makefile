NAME = replace

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror  

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	c++ ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	$(RM) ${OBJ}

fclean : clean
	$(RM) ${NAME}

re : fclean all