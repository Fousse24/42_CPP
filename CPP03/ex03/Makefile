# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 20:58:38 by sfournie          #+#    #+#              #
#    Updated: 2022/03/01 16:22:52 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98
DFLAGS	= -d

C_OBJS	= $(CC) $(CFLAGS) $(INCS) -c $< -o $@
C_MAIN	= $(CC) $(CFLAGS) $(INCS)

# NAME
NAME	= ex03
P_NAME	= "Now it gets weird"

# Mains
MAIN	= main.cpp

# Directories
D_SRCS	= srcs
D_INCS	= includes
D_OBJS	= objs
D_MAIN	= main

INCS	= -I$(D_INCS)

# Headers
HEADS	= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

# Sources
SRCS	= ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

# Objects
OBJS	= $(SRCS:.c=.o)

$(D_OBJS)/%.o :  %.c $(HEADS)
		 @ $(C_OBJS)

# Rules/Recipes
all		: $(NAME)

$(NAME)	: $(HEADS) $(SRCS) $(OBJS) $(MAIN)
		@ $(C_MAIN) $(MAIN) $(OBJS) -o $(NAME)
		# $(shell echo "Compiling $(P_NAME) done!")
		# $(shell echo "Executable is : $(NAME)")

$(D_OBJS):
		@ mkdir $(D_OBJS)

clean	: 
		@ rm -rf $(D_OBJS)
		# $(shell echo "Cleaning done!")

fclean	: clean
		@ rm -f $(NAME)

re		: fclean all

debug	: _debug $(NAME)

_debug	:
		$(eval CFLAGS=$(CFLAGS) $(DFLAGS))

.PHONY	: all clean fclean re debug
		