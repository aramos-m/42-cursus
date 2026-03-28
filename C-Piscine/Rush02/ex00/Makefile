NAME = rush-02

MY_SOURCES = main.c \
			 tools.c \
			 division.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS) 
		cc $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)
