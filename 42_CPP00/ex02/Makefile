# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 13:45:04 by del-ganb          #+#    #+#              #
#    Updated: 2025/04/24 13:45:05 by del-ganb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY : all clean fclean re
