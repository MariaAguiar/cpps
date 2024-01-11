
#include <iostream>
#include <fstream>

int main( int ac, char **av )
{
	if (ac != 4)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::ifstream filename;
  	filename.open (av[1], std::ifstream::binary);
	
	if (filename.fail())
	{
		std::cerr << "Couldn't open file" << std::endl;
		return 1;
	}
	std::string line;
	std::string outfile = av[1];
	outfile += ".replace";
	std::ofstream output(outfile.c_str());

	std::string s;
	int sum = 0;
	char c;
    output.flush();
	std::string s2 = av[2];
	while (std::getline(filename, s))
	{
		size_t pos = 0;
		sum += s.size();
		while (pos < s.size() - 1)
		{
			pos = s.find(s2, pos);
			if (pos == std::string::npos)
				break ;
			int i = 0;
			for (i = 0; av[2][i]; i++)
			{
				if (av[3][i])
					s[pos++] = av[3][i];
				else
				{
					s.erase(pos, s2.size() - i);
					break ;
				}
			}
			if (av[3][i])
			{
				s.insert(pos, &av[3][i]);
				std::string aux = &av[3][i];
				pos += aux.size();
			}
		}
		filename.seekg(sum, filename.beg);
		filename.get(c);
		sum++;
		output << s << c;
	}
	output.close();
  	filename.close();

    return 0;
}
