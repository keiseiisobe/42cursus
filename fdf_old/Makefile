# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 08:33:17 by kisobe            #+#    #+#              #
#    Updated: 2024/02/01 09:47:06 by kisobe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c Libft/ft_atoi.c Libft/ft_split.c Libft/ft_strlen.c Libft/ft_substr.c GetNextLine/get_next_line.c GetNextLine/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Imlx -c $< -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
