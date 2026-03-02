
NAME = my_awesome_phonebook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp \
		Contact.cpp \
		PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re