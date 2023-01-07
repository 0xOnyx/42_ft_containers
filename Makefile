NAME = stl

SRC = main.cpp
HEADER_PATH = ./src/
HEADER = vector.hpp random_access_iterator.hpp iterator.hpp
HEADERS = $(addprefix $(HEADER_PATH),$(HEADER))
OBJS = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O3 -I$(HEADER_PATH)
CC = c++
RM = rm -rf

all: $(NAME)

test:
	echo $(HEADERS)

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