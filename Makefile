# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gricquie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 20:51:53 by gricquie          #+#    #+#              #
#    Updated: 2017/02/05 01:11:32 by gricquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c

HEADER = minishell.h
HEADERLIBFT = libft.h

OBJS = $(SRCS:.c=.o)

SRCSDIR = srcs/
OBJDIR = objs/
HEADERDIR = includes/
LIBFTDIR = libft/

OBJFULL = $(addprefix $(OBJDIR), $(OBJS))

FLAGS = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) : $(OBJFULL) $(addprefix $(HEADERDIR), $(HEADER)) $(addprefix $(LIBFTDIR), $(HEADERLIBFT))
	gcc -o $(NAME) $(OBJFULL) -L $(LIBFTDIR) -lft

$(OBJDIR)%.o : $(SRCSDIR)%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR) -I $(LIBFTDIR) -L $(LIBFTDIR) -lft

clean :
	rm -f $(OBJFULL)
	rmdir $(OBJDIR) 2> /dev/null || true

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
