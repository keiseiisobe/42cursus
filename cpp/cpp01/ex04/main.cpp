#include <fstream>
#include <iostream>
#include <string>

enum {ARG, OPEN, CAST};

std::string	safety_cast(char *v)
{
	std::string r = static_cast<std::string>(v);
	if (std::strcmp(r.c_str(), v) != 0)
		throw std::runtime_error("");
	return r;
}

void	check_init_error(bool is_error, int flag)
{
	if (!is_error)
		return;
	switch (flag)
	{
		case ARG:
			std::cout << "Note: ./Sed_is_for_losers <filename> <string1> <string2>" << std::endl;
			break;
		case OPEN:
			std::cout << "Failed to open a file." << std::endl;
			break;
		case CAST:
			std::cout << "Failed to cast safely." << std::endl;
			break;
	}
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	check_init_error(argc != 4, ARG);
	std::string	filename;
	std::string	s1;
	std::string	s2;
	try
	{
		filename = safety_cast(argv[1]);
		s1 = safety_cast(argv[2]);
		s2 = safety_cast(argv[3]);
	}
	catch (std::runtime_error)
	{
		check_init_error(true, CAST);
	}
	std::ifstream	ifs(filename);
	check_init_error(!ifs.is_open(), OPEN);
	std::ofstream	ofs(filename + ".replace");
	check_init_error(!ofs.is_open(), OPEN);
	std::string		line;
	unsigned int	i;
	while (std::getline(ifs, line))
	{
		i = 0;
		std::string::size_type	pos = line.find(s1);
		while (pos != std::string::npos)
		{
			for (;i < static_cast<unsigned int>(pos);i++)
				ofs << line[i];
			ofs << s2;
			i += s1.length();
			pos = line.find(s1, pos + s1.length());
		}
		for (;i < static_cast<unsigned int>(line.length());i++)
			ofs << line[i];
		ofs << std::endl;
	}
	return 0;
}
