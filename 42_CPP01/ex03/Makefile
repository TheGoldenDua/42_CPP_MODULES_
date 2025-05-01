NAME = Unnecessary_violence

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

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