#include "PhoneBook.hpp"

static int	num_of_elem = 0;

PhoneBook::PhoneBook(const int sz)
{
	size = sz;
	std::cout << "***** Welcome to our awesome PhoneBook Service *****" << std::endl << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Successfully PhoneBook closed!" << std::endl;
}

int	PhoneBook::get_size() const
{
	return (size); }

void	PhoneBook::add_contact(t_info *contact)
{
	int	index;

	num_of_elem++;
	if (num_of_elem > size)
	{
		index = size - 1;
		num_of_elem--;
	}
	else
		index = num_of_elem - 1;
	move_contact(index);
	contacts[0].first_name = contact->first_name;
	contacts[0].last_name = contact->last_name;
	contacts[0].nickname = contact->nickname;
	contacts[0].phone_number = contact->phone_number;
	contacts[0].darkest_secret = contact->darkest_secret;
}

void	PhoneBook::move_contact(int i)
{
	for (; i > 0; i--)
		contacts[i] = contacts[i - 1];
}

std::string	accept_next_command(void)
{
	std::string	input;

	while (1)
	{
		std::cout << "Enter 'CONTINUE' to continue searching," << std::endl;
		std::cout << "or Enter 'TOP' to go back to the top page" << std::endl;
		getline(std::cin, input);
		if (input.length() != 0)
		{
			if (input == "CONTINUE" || input == "TOP")
				return (input);
			else
			{
				std::cout << "Invalid command !" << std::endl;
				std::cout << "Retry" << std::endl << "..." << std::endl << "..." << std::endl;
			}
		}
	}
}

std::string	handle_char_wide(std::string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	for (int i = 10 - static_cast<int>(str.length());i > 0;i--)
		std::cout << " ";
	return (str);
}

void	print_each_contact(std::string str)
{
	std::string	output;

	output = handle_char_wide(str);
	std::cout << output << "|";
}

int	PhoneBook::print_all_contacts() const
{
	if (num_of_elem <= 0)
	{
		std::cout << "Your phonebook is empty." << std::endl;
		return (num_of_elem);
	}
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < num_of_elem; i++)
	{
		std::cout << "|";
		print_each_contact(std::to_string(i + 1));
		print_each_contact(contacts[i].first_name);
		print_each_contact(contacts[i].last_name);
		print_each_contact(contacts[i].nickname);
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
	return (num_of_elem);
}

void	PhoneBook::print_contact(int i) const
{
	std::cout << "index: " << i + 1 << std::endl;;
	std::cout << "first name: " << contacts[i].first_name << std::endl;
	std::cout << "last name: " << contacts[i].last_name << std::endl;
	std::cout << "nickname: " << contacts[i].nickname << std::endl;
	std::cout << "phone number: " << contacts[i].phone_number << std::endl;
	std::cout << "darkest_secret: " << contacts[i].darkest_secret << std::endl;
}
