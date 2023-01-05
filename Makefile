NAME = stl

SRC = main.cpp
HEADER_PATH = /src
HEADER = Vector.tpp
HEADERS = $(addprefix $(HEADER_PATH),$(HEADER))
OBJS = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O3
CC = c++
RM = rm -rf

SRCS =
all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) -o $(@) -c $(<)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(@) $(^)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re