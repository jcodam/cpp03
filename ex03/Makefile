NAME= ex2

SRC= main.o Fixed.o

CC= c++

CPPFLAGS +=	-Wall -Werror -Wextra
CPPFLAGS +=	-std=c++98
CPPFLAGS += -fsanitize=address

all:$(NAME)

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) -o $@ $^
%.o:%.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(SRC)
fclean:
	rm -rf $(SRC) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

r: all
	./$(NAME)

.PHONY: all clean fclean re r 