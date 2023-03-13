# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 13:42:37 by sfournie          #+#    #+#              #
#    Updated: 2022/03/23 18:01:13 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC		= clang++
CFLAGS	=  -Werror -Wall -Wextra -Wshadow -Wconversion -std=c++98
C_OBJS	= $(CC) $(CFLAGS) $(INCS) -c $< -o $@
C_MAIN	= $(CC) $(CFLAGS) $(INCS) $(OBJS) $(MAIN) -o $(NAME)

# Program
NAME	= ex02
DESC	= \"Identify real type\"

# Directories
SRCS_D	= .
INCS_D	= .
OBJS_D	= objs

# Files
MAIN	= main.cpp

_HEADS	= 	Base.hpp A.hpp B.hpp C.hpp
HEADS	=	$(patsubst %.hpp, $(INCS_D)/%.hpp, $(_HEADS))

_SRCS	= 	Base.cpp A.cpp B.cpp C.cpp
SRCS	=	$(patsubst %.cpp, $(SRCS_D)/%.cpp, $(_SRCS))

_OBJS	= $(_SRCS:.cpp=.o)
OBJS	= $(patsubst %.o, $(OBJS_D)/%.o, $(_OBJS))

$(OBJS_D)/%.o : %.cpp
		$(C_OBJS)

# Recipes
all		: $(NAME)

$(NAME)	: $(HEADS) $(SRCS) $(OBJS_D) $(OBJS) $(MAIN)
		$(C_MAIN)
		# $(shell echo "Compiling $(P_NAME) done!")
		# $(shell echo "Executable is : $(NAME)")

$(OBJS_D)	:
		@ mkdir $(OBJS_D)

clean	: 
		@ rm -rf $(OBJS_D)
		# $(shell echo "Cleaning done!")

fclean	: clean
		@ rm -f $(NAME)

re		: fclean all

test	: fclean _test $(NAME)

_test	:
		$(eval CFLAGS= -Wall -Wextra -Wshadow -Wconversion -std=c++98)

.PHONY	: all clean fclean re test




