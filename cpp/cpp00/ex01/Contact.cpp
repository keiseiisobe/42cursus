#include "Contact.hpp"

t_info	*Contact::put_all_contact_fields()
{
	std::string	input;

	while (1)
	{
		put_first_name(input);
		std::cout << input << std::endl;
		std::cout << "Enter your last name" << std::endl;
		std::cin >> input;
		std::cout << input << std::endl;
		break;
	}
	return nullptr;
}

void	Contact::put_first_name()
{
	while (1)
	{
		std::cout << "Enter your first name: " << std::endl;
		std::cin >> input;
		if (is_valid(input) == true)
		{
			contact.first_name = input;
			break ;
		}
	}
}
