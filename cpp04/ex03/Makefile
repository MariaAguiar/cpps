NAME = Materia
CXX = c++ -g
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
INCS = AMateria.hpp ICharacter.hpp Character.hpp \
       Cure.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp
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
