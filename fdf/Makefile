# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 08:33:17 by kisobe            #+#    #+#              #
#    Updated: 2024/02/12 09:42:06 by kisobe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c read.c draw.c deform.c color.c event.c error.c
OBJS = $(SRCS:.c=.o)
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFTOBJS = $(LIBFTDIR)/*.o
INCLUDE = -I./include -I$(LIBFTDIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		$(CC) $(INCLUDE) $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C $(LIBFTDIR)
		$(CC) $(CFlAGS) $(LIBFT) -Imlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

clean :
		rm -f $(OBJS)
		rm -f $(LIBFTOBJS)

fclean : clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
