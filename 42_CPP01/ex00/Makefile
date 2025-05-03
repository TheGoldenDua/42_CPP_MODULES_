# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 00:55:04 by del-ganb          #+#    #+#              #
#    Updated: 2025/05/03 00:55:05 by del-ganb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRC = newZombie.cpp main.cpp Zombie.cpp randomChump.cpp

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
