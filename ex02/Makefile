# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toshota <toshota@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 16:13:09 by toshota           #+#    #+#              #
#    Updated: 2024/06/13 18:59:28 by toshota          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM			=	rm -rf
OBJS_DIR	=	objs/

SRCS		=	$(wildcard *.cpp)
HEADERS		=	$(wildcard *.hpp)
SHS			=	$(wildcard *.sh)
OBJS		=	$(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))

ifeq ($(MAKECMDGOALS), debug)
	FLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

ifeq ($(MAKECMDGOALS), test)
	FLAGS += -DTEST
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:
	$(RM) $(OBJS_DIR) $(NAME)

re:		fclean all

format:
	$(if $(SRCS), clang-format --style=Google -i $(SRCS))
	$(if $(HEADERS), clang-format --style=Google -i $(HEADERS))
	$(if $(SHS), shfmt -w $(SHS))

debug: re

address: re

test:
	 ./test.sh

.PHONY:	all clean fclean re format debug address test
