NAME = philo
SRCS = arg.c arg_utils/arg_utils.c arg_utils/ft_atoi.c\
	   arg_utils/ft_isdigit.c error.c free.c init.c\
	   join.c main.c monitor.c routine.c wrapper.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
