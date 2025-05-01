
NAME = horde

SRC = Zombie.cpp main.cpp zombieHorde.cpp

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

PHONY : all clean fclean re