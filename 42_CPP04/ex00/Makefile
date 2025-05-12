# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 16:09:54 by del-ganb          #+#    #+#              #
#    Updated: 2025/05/12 16:09:55 by del-ganb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Override

SRC = main.cpp srcs/Animal.cpp srcs/Dog.cpp srcs/Cat.cpp srcs/WrongCat.cpp srcs/WrongAnimal.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
