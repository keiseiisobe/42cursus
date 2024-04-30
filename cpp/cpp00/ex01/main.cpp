#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook	pb(8);
	Contact		c;
	t_info		contact;
	std::string	input;
	int			index;
	int			num_of_elem;

	while (1)
	{
		std::cout << "Enter your command ( ADD, SEARCH, EXIT ):" << std::endl;
		getline(std::cin, input);
		if (input.length() != 0)
		{
			if (input == "ADD")
			{
				c.put_all_fields_into_contact(&contact);
				pb.add_contact(&contact);
				std::cout << "Successfully added new contact!" << std::endl;
			}
			else if (input == "SEARCH")
			{
				if ((num_of_elem = pb.print_all_contacts()) > 0)
				{
					std::cout << "Enter an index of which is a contact you want to see:" << std::endl;
					getline(std::cin, input);
					if (valid_number(input))
					{
						index = std::stoi(input);
						if (index >= 1  && index <= num_of_elem)
							pb.print_contact(index - 1);
						else
							std::cout << "Invalid index !" << std::endl;
					}
					else
						std::cout << "Invalid index !" << std::endl;
				}
			}
			else if (input == "EXIT")
				break ;
			else
			{
				std::cout << "Invalid command !" << std::endl;
				std::cout << "Retry..." << std::endl;
			}
			std::cout << std::endl << std::endl;
		}
	}
	return 0;
}
