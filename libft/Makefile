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

NAME = libft.a

LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
		ft_strncpy.c ft_strcat.c ft_strlcat.c ft_strchr.c ft_strchr.c\
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_atoi.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c\
		ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c\
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
		ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
		ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isupper.c\
		ft_islower.c ft_putnbrl.c ft_putnbrl_fd.c ft_realloc.c\
		ft_strsplitcharset.c ft_printtab.c ft_swap.c ft_lstdeljoin.c

HEADER = libft.h

OBJLIBFT = $(LIBFT:.c=.o)

FLAGS = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) : $(OBJLIBFT) $(HEADER)
	@ar -rc $(NAME) $(OBJLIBFT)
	@ranlib $(NAME)

%.o : %.c
	@gcc -o $@ -c $< $(FLAGS)

clean :
	@rm -f $(OBJLIBFT)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
