# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: botilia <botilia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 18:39:08 by botilia           #+#    #+#              #
#    Updated: 2022/07/15 14:29:02 by botilia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc

LIBDIR	=	libft
LIBFT	=	libft.a

UNAME	=	$(shell uname)
ifeq ($(UNAME),Linux)
	MINDIR	= 	mlx_linux
	MINLIBX	=	libmlx.a
	MLX_FLAGS = -I$(MINDIR) -lXext -lX11 -lm -lz
else
	MINDIR	= 	mlx
	MINLIBX	=	libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit 
endif

HEADERS	=	src/cub3d.h gnl/get_next_line.h libft/libft.h

SRC		=	$(wildcard gnl/*.c)	\
			$(wildcard src/*.c)

OBJ		=	$(patsubst %.c,%.o,$(SRC))

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADERS)
		@make -C $(LIBDIR)/
		@cp	$(LIBDIR)/$(LIBFT) .
		@make -C $(MINDIR)/
		@cp	$(MINDIR)/$(MINLIBX) .
		$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINLIBX) -o $(NAME) -L$(MINDIR) -lmlx $(MLX_FLAGS)
		
clean:
		@rm -rf $(OBJ)
		@make -C $(LIBDIR) clean
		@make -C $(MINDIR) clean

fclean: clean
		@make -C $(LIBDIR) fclean
		@rm -f $(NAME)
		@rm -f $(MINLIBX)
		@rm -f $(LIBFT)
		
re: 	fclean all

bonus:	all

norm:
	norminette src/*.c src/*.h gnl/*.c gnl/*.h libft/*.c libft/*.h
	

.PHONY	:	all clean fclean re
