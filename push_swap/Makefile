# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 08:33:17 by kisobe            #+#    #+#              #
#    Updated: 2024/02/24 09:31:13 by kisobe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c init.c instructions.c sort_small.c sort_a.c sort_b.c calculate.c\
	   calculate_utils.c arg.c error.c free.c
OBJS = $(SRCS:.c=.o)
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFTOBJS = $(LIBFTDIR)/*.o
INCLUDE = -I./include -I$(LIBFTDIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C $(LIBFTDIR)
		$(CC) $(CFlAGS) $(LIBFT) $^ -o $@

clean :
		rm -f $(OBJS)
		rm -f $(LIBFTOBJS)

fclean : clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
