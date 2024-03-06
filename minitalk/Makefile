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

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_S) $(NAME_C)

$(NAME_S) : $(SRCS_S)
	$(CC) $(CFLAGS) -o $(NAME_S) $(SRCS_S)

$(NAME_C) : $(SRCS_C)
	$(CC) $(CFLAGS) -o $(NAME_C) $(SRCS_C)

bonus: $(NAME_S_B) $(NAME_C_B)

$(NAME_S_B) : $(SRCS_S_B)
	$(CC) $(CFLAGS) -o $(NAME_S_B) $(SRCS_S_B)

$(NAME_C_B) : $(SRCS_C_B)
	$(CC) $(CFLAGS) -o $(NAME_C_B) $(SRCS_C_B)

clean:
	rm -f $(OBJS_S) $(OBJS_C) $(OBJS_S_B) $(OBJS_C_B)

fclean: clean
	rm -f $(NAME_S) $(NAME_C) $(NAME_S_B) $(NAME_C_B)

re: fclean all

.PHONY: all clean fclean re
