NAME = ex01
MAIN = main.cpp
SRCS = Span.cpp
OBJS = $(SRCS:.cpp=.o) main.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS) test.o

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)

re: fclean all

TEST_NAME = ex01Test
TEST_OBJS = $(SRCS:.cpp=.o) test.o

$(TEST_NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $(TEST_NAME)

test: $(TEST_NAME)

.PHONY: all clean fclean re test
