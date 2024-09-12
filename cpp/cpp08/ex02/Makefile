NAME = mutantStack
OBJS = main.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

TEST_OBJS = test.o

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $(NAME)

.PHONY: all clean fclean re
