NAME= clapParty

SRC= ClapTrap.o ScavTrap.o FragTrap.o DiamondTrap.o
HEADER:= $(SRC:%.o=%.hpp)
SRC+= main.o

CC= c++

CPPFLAGS +=	-Wall -Werror -Wextra
CPPFLAGS +=	-std=c++98
CPPFLAGS += -Wshadow -Wno-shadow

all:$(NAME)

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) -o $@ $^
%.o:%.cpp $(HEADER)
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

.PHONY: all clean fclean re r m