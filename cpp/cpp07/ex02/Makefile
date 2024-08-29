NAME = array
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -fsanitize=address -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
