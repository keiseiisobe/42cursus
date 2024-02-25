# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 08:33:17 by kisobe            #+#    #+#              #
#    Updated: 2024/02/25 15:20:09 by kisobe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = main.c arg.c arg_check_utils/check_double_quote.c arg_check_utils/is_dupe.c\
	   arg_check_utils/is_int.c arg_check_utils/is_int_max.c calculate.c\
	   calculate_utils.c count.c count_utils/count_ra.c count_utils/count_rra.c\
	   count_utils/count_rb.c count_utils/count_rrb.c error.c free.c init.c instructions.c\
	   instructions_utils.c move.c push_swap.c sort.c sort_few.c sort_many.c vector.c
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
