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
	rm -rf $(NAME)

re: fclean all

TEST = test.cpp
TEST_OBJS = $(SRCS:.cpp=.o) test.o

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $(NAME)

.PHONY: all clean fclean re
