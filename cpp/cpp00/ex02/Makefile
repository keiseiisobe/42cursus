NAME = account
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
