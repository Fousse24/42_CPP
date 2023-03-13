# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 20:58:38 by sfournie          #+#    #+#              #
#    Updated: 2022/02/15 17:13:01 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC		= c++
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -d

C_OBJS	= $(CC) $(CFLAGS) $(INCS) -c $< -o $@
C_MAIN	= $(CC) $(CFLAGS) $(INCS)

# NAME
NAME	= megaphone
P_NAME	= Megaphone

# Mains
MAIN	= Megaphone.cpp

# Directories
D_SRCS	= srcs
D_INCS	= includes
D_OBJS	= objs
D_MAIN	= main

INCS	= -I$(D_INCS)

# Headers
HEADS	= 

# Sources
_SRCS	=
SRCS	= $(patsubst %, $(D_SRCS)/%, $(_SRCS))

# Objects
_OBJS	= $(_SRCS:.c=.o)
OBJS	= $(patsubst %, $(D_OBJS)/%, $(_OBJS))

# vpath
vpath %.c $(D_SRCS)

$(D_OBJS)/%.o :  %.c $(HEADS)
		 @ $(C_OBJS)

# Rules/Recipes
all		: $(NAME)

$(NAME)	: $(MAIN)
		@ $(C_MAIN) $(MAIN) -o $(NAME)
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
		