# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 10:14:13 by del-ganb          #+#    #+#              #
#    Updated: 2025/06/27 10:14:14 by del-ganb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form_28B

SRC = main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp srcs/ShrubberyCreationForm.cpp srcs/PresidentialPardonForm.cpp srcs/RobotomyRequestForm.cpp

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
