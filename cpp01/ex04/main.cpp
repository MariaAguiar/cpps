
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

int main( int ac, char **av )
{
	if (ac != 4)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::ifstream filename;
  	filename.open (av[1], std::ifstream::binary);
	
	std::string line;
	std::string outfile = av[1];
	outfile += ".replace";
	std::ofstream output(outfile.c_str());

	std::string s;
	int sum = 0;
	char c;
    output.flush();
	while (std::getline(filename, s))
	{
		size_t pos = 0;
		while (pos < s.size() - 1)
		{
			std::string s2 = av[2];
			pos = s.find(s2, pos);
			if (pos >= s.size() - 1)
				break;
			int i = 0;
			for (i = 0; av[2][i]; i++)
			{
				if (av[3][i])
					s[pos++] = av[3][i];
			}
			while (av[3][i] && s[pos] != '\n' && s[pos] != '\0')
				s[pos++] = av[3][i++];
			if (av[3][i])
				s.insert(pos, &av[3][i]);
		}
		sum += s.size();
		filename.seekg(sum, filename.beg);
		filename.get(c);
		sum++;
		output << s << c;
	}
	output.close();
  	filename.close();

    return 0;
}