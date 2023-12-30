#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac > 1)	
	{
		for(int i = 1; i < ac; i++)
		{
			for(int f = 0; av[i][f]; f++)
				av[i][f] = std::toupper(av[i][f]);
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 1;
}