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
	rm -rf $(NAME) $(TEST_NAME)

re: fclean all

TEST_NAME = mutantStackTest
TEST_OBJS = test.o

$(TEST_NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $(TEST_NAME)

test: $(TEST_NAME)

.PHONY: all clean fclean re test
