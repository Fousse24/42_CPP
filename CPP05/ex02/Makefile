# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 13:42:37 by sfournie          #+#    #+#              #
#    Updated: 2022/03/15 17:30:44 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC		= clang++
CFLAGS	= -Werror -Wall -Wextra -Wshadow -std=c++98
C_OBJS	= $(CC) $(CFLAGS) $(INCS) -c $< -o $@
C_MAIN	= $(CC) $(CFLAGS) $(INCS) $(OBJS) $(MAIN) -o $(NAME)

# Program
NAME	= ex02
DESC	= \"Oh, no, you need form 28B, not 28C...\"

# Directories
SRCS_D	= .
INCS_D	= .
OBJS_D	= objs

# Files
MAIN	= main.cpp

_HEADS	= 	Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp\
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp
HEADS	=	$(patsubst %.hpp, $(INCS_D)/%.hpp, $(_HEADS))

_SRCS	= 	Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp
SRCS	=	$(patsubst %.cpp, $(SRCS_D)/%.cpp, $(_SRCS))

_OBJS	= $(_SRCS:.cpp=.o)
OBJS	= $(patsubst %.o, $(OBJS_D)/%.o, $(_OBJS))

$(OBJS_D)/%.o : %.cpp
		$(C_OBJS)

# Recipes
all		: $(NAME)

$(NAME)	: $(HEADS) $(SRCS) $(OBJS_D) $(OBJS) $(MAIN)
		$(C_MAIN)
		# $(shell echo "Compiling $(DESC) done!")
		# $(shell echo "Executable is : $(NAME)")

$(OBJS_D)	:
		@ mkdir $(OBJS_D)

clean	: 
		@ rm -rf $(OBJS_D)
		# $(shell echo "Cleaning done!")

fclean	: clean
		@ rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re




