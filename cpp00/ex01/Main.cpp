#include "PhoneBook.hpp"

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	while (!std::cin.eof())
	{
		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.Add();
		else if (input == "SEARCH")
			phonebook.Search();
		else if (input == "EXIT")
			break ;
	}

	return 0;
}
