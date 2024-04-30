#include "Contact.hpp"

void	Contact::put_all_fields_into_contact(t_info *contact)
{
	put_first_name(contact);
	put_last_name(contact);
	put_nickname(contact);
	put_phone_number(contact);
	put_darkest_secret(contact);
}

bool	valid_name(const std::string first_name)
{
	if (first_name.length() == 0)
		return false;
	for (int i = 0; i < static_cast<int>(first_name.length()); i++)
		// should cast be modified ???
		if (!std::isalpha(first_name[i]))
			return false;
	std::cout << "Validated!" << std::endl;
	return true;
}

bool	valid_number(const std::string number)
{
	if (number.length() == 0)
		return false;
	for (int i = 0; i < static_cast<int>(number.length()); i++)
		// should cast be modified ???
		if (!std::isdigit(number[i]))
			return false;
	std::cout << "Validated!" << std::endl;
	return true;
}

void	Contact::put_first_name(t_info *contact)
{
	std::string	input;

	while (1)
	{
		std::cout << "Enter your first name: " << std::endl;
		getline(std::cin, input);
		if (valid_name(input))
		{
			contact->first_name = input;
			break ;
		}
		std::cout << "Invalid format for 'first name'!" << std::endl;
		std::cout << "Retry..." << std::endl;
	}
};

void	Contact::put_last_name(t_info *contact)
{
	std::string	input;

	while (1)
	{
		std::cout << "Enter your last name: " << std::endl;
		getline(std::cin, input);
		if (valid_name(input))
		{
			contact->last_name = input;
			break ;
		}
		std::cout << "Invalid format for 'last name'!" << std::endl;
		std::cout << "Retry..." << std::endl;
	}
};

void	Contact::put_nickname(t_info *contact)
{
	std::string	input;

	while (1)
	{
		std::cout << "Enter your nickname: " << std::endl;
		getline(std::cin, input);
		if (input.length() != 0)
		{
			contact->nickname = input;
			break ;
		}
		std::cout << "Invalid format for 'nickname'!" << std::endl;
		std::cout << "Retry..." << std::endl;
	}
};

void	Contact::put_phone_number(t_info *contact)
{
	std::string	input;

	while (1)
	{
		std::cout << "Enter your phone number ( without '-' ): " << std::endl;
		getline(std::cin, input);
		if (valid_number(input))
		{
			contact->phone_number = input;
			break ;
		}
		std::cout << "Invalid format for 'phone number'!" << std::endl;
		std::cout << "Retry..." << std::endl;
	}
};

void	Contact::put_darkest_secret(t_info *contact)
{
	std::string	input;

	while (1)
	{
		std::cout << "Enter your darkest secret: " << std::endl;
		getline(std::cin, input);
		if (input.length() != 0)
		{
			contact->darkest_secret = input;
			break ;
		}
		std::cout << "Invalid format for 'darkest secret'!" << std::endl;
		std::cout << "Retry..." << std::endl;
	}
};
