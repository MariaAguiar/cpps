NAME = DiamondTrap
CXX = c++
CXXFLAGS = -std=c++98 -Wshadow -Wall -Wextra -Werror
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
INCS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
OBJ = $(SRC:%.cpp=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^

obj/%.o: %.cpp $(INCS)
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
