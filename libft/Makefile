# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: botilia <botilia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 11:12:28 by botilia           #+#    #+#              #
#    Updated: 2022/07/15 11:18:33 by botilia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

ONE	=	ft_isprint.c	ft_putchar_fd.c		ft_strjoin.c	ft_strtrim.c\
		ft_atoi.c		ft_itoa.c		ft_putendl_fd.c		ft_strlcat.c	ft_substr.c\
		ft_bzero.c		ft_putnbr_fd.c	ft_strlcpy.c		ft_tolower.c\
		ft_calloc.c		ft_memchr.c		ft_putstr_fd.c		ft_strlen.c		ft_toupper.c\
		ft_memcmp.c		ft_isalnum.c	ft_split.c			ft_strmapi.c\
		ft_memcpy.c		ft_isalpha.c	ft_strchr.c			ft_strncmp.c\
		ft_strdup.c		ft_isascii.c	ft_memmove.c		ft_strnstr.c\
		ft_memset.c		ft_isdigit.c	ft_striteri.c		ft_strrchr.c

TWO	=	ft_lstmap.c		ft_lstnew.c		ft_lstadd_back.c	ft_lstsize.c	ft_lstadd_front.c\
		ft_lstclear.c	ft_lstdelone.c 	ft_lstiter.c		ft_lstlast.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(patsubst %.c,%.o,$(ONE))
OBJ_T = $(patsubst %.c,%.o,$(TWO))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
	
%.o : %.c
	@gcc $(FLAGS) -c $< -o $@
	
bonus :
	make OBJ="$(OBJ_T)" all
	
clean	: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus