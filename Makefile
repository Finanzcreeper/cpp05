CXX = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = Bureaucrat
SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CFLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

.PHONY: clean fclean re
