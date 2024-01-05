#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

void PhoneBook::Add()
{
	std::string input;

	for (int i = 0; i <= 4; i++)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		switch (i)
		{
		case 0:
			std::cout << "Enter First Name: ";
			break;
		case 1:
			std::cout << "Enter Last Name: ";
			break;
		case 2:
			std::cout << "Enter Nickname: ";
			break;
		case 3:
			std::cout << "Enter Phone Number: ";
			break;
		case 4:
			std::cout << "Enter Darkset Secret: ";
			break;
		default:
			break;
		}
		std::getline(std::cin, input);
		if (input.size() > 0)
			contacts[index].setString(input, i);
		else
		{
			for (int f = 0; f < i; f++)
				contacts[index].setString("", f);
		}
	}
	if (contacts[index].getString(0).size() > 0)
	{
		index++;
		if (index == 8)
			index = 0;
	}
}

void PhoneBook::Search()
{
	int i;

	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (i = 0; i <= 7; i++)
	{
		if (contacts[i].getString(0).size() == 0)
			break ;
		std::cout << "|";
		for (int f = 0; f <= 3; f++)
		{
			if (f == 0)
			{
				std::cout << std::setfill (' ') << std::setw (10);
				std::cout << i << "|";
				continue ;
			}
			std::string output = contacts[i].getString(f - 1);
			if (output.length() > 9)
			{
				output.replace(9, 1, ".");
				output.resize(10);
			}
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << output;
			std::cout << "|";
		}
		std::cout << std::endl;
	}

	std::string input;
	int	num;
	while (i > 0 && !std::cin.eof())
	{
		std::cout << "Input a valid index to display full entry info: ";
		std::getline(std::cin, input);
		std::stringstream ss(input);
		ss >> num;
		if (!ss.fail() && num >= 0 && num < i)
		{
			for (int f = 0; f <= 4; f++)
			{
				switch (f)
				{
				case 0:
					std::cout << "First Name: ";
					break;
				case 1:
					std::cout << "Last Name: ";
					break;
				case 2:
					std::cout << "Nickname: ";
					break;
				case 3:
					std::cout << "Phone Number: ";
					break;
				case 4:
					std::cout << "Darkset Secret: ";
					break;
				default:
					break;
				}
				std::cout << contacts[num].getString(f) << std::endl;
			}
			break ;
		}
		else
			std::cout << "Invalid Index. ";
	}
}

PhoneBook::~PhoneBook(){}
