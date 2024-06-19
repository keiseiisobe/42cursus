# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kisobe <kisobe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 16:19:06 by kisobe            #+#    #+#              #
#    Updated: 2024/02/11 12:47:24 by kisobe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c \
			ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
			ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c \
			ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c \
			ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c \
			ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c \
			ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c\
			if_something1.c if_something2.c ft_put_something1.c ft_put_something2.c\
			ft_printf.c get_next_line_utils.c get_next_line.c
OBJS	=	$(SRCS:.c=.o)
CC	=	cc
#CFLAGS	=	-Wall -Wextra -Werror

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)
all:$(NAME)
	
clean:
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re
