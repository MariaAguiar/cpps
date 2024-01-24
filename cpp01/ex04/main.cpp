
#include <iostream>
#include <fstream>

int main( int ac, char **av )
{
	if (ac != 4)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string s2 = av[2];
	if (s2.empty())
	{
		std::cerr << "Invalid substitution sequence" << std::endl;
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
    output.flush();
	int flag = 0;
	size_t pos;
	std::string s3 = av[3];
	while (std::getline(filename, s))
	{
		pos = 0;
		while (s2.size() && pos < s.size())
		{
			pos = s.find(s2, pos);
			if (pos == std::string::npos)
				break ;
			s.erase(pos, s2.size());
			s.insert(pos, av[3]);
			pos += s3.size();
		}
		if (flag == 1)
			output << '\n';
		output << s;
		flag = 1;
	}
	if (s == "\0" && flag == 1)
		output << "\n";
	output.close();
  	filename.close();

    return 0;
}