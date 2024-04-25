#include <iostream>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc >= 2)
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				if (std::islower(argv[i][j]))
					std::cout << static_cast<char>(std::toupper(argv[i][j]));
				else
					std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
