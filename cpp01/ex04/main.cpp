
#include <iostream>
#include <fstream>
#include <sstream>

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
    output.flush();

	std::string s;
	size_t pos = 0;
	std::string s3 = av[3];
	std::stringstream	ss;
	
	ss << filename.rdbuf();
	s = ss.str();
	pos = s.find(s2, 0);
	while (pos != std::string::npos)
	{
		s.erase(pos, s2.size());
		s.insert(pos, s3);
		pos = s.find(s2, pos + s3.size());
	}
	output << s;
	output.close();
  	filename.close();

    return 0;
}