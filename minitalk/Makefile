# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 10:28:27 by kisobe            #+#    #+#              #
#    Updated: 2024/03/08 11:07:41 by kisobe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_S_B = server_bonus
NAME_C_B = client_bonus
SRCS_S = server.c error.c
SRCS_C = client.c error.c
SRCS_S_B = bonus/server_bonus.c bonus/set_bonus.c bonus/handle_bit_bonus.c\
			bonus/ready_bonus.c bonus/error_bonus.c bonus/free_bonus.c
SRCS_C_B = bonus/client_bonus.c bonus/set_bonus.c bonus/handle_bit_bonus.c\
			bonus/ready_bonus.c bonus/error_bonus.c bonus/free_bonus.c
OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S_B = $(SRCS_S_B:.c=.o)
OBJS_C_B = $(SRCS_C_B:.c=.o)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFTOBJS = $(LIBFTDIR)/*.o
INCLUDE = -I./include -I$(LIBFTDIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_S) $(NAME_C)

%.o : %.c
	$(CC) $(INCLUDE) $(CFlAGS) -c $< -o $@

$(NAME_S) : $(OBJS_S)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS_S) $(LIBFT) -o $(NAME_S)

$(NAME_C) : $(OBJS_C)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) -o $(NAME_C)

bonus: $(NAME_S_B) $(NAME_C_B)

$(NAME_S_B) : $(OBJS_S_B)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS_S_B) $(LIBFT) -o $(NAME_S_B)

$(NAME_C_B) : $(OBJS_C_B)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS_C_B) $(LIBFT) -o $(NAME_C_B)

clean:
	rm -f $(OBJS_S) $(OBJS_C) $(OBJS_S_B) $(OBJS_C_B) $(LIBFTOBJS)

fclean: clean
	rm -f $(NAME_S) $(NAME_C) $(NAME_S_B) $(NAME_C_B) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
