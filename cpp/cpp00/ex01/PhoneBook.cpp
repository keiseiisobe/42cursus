#include "PhoneBook.hpp"

static int	num_of_elem = 0;

PhoneBook::PhoneBook(const int sz)
{
//	if (sz <= 0)
	size = sz;
	std::cout << "Successfully PhoneBook constructed!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Successfully PhoneBook destructed!" << std::endl;
}

int	PhoneBook::get_size() const
{
	return (size);
}

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
//	if (i < 0)
	for (; i > 0; i--)
		contacts[i] = contacts[i - 1];
}

int	PhoneBook::print_all_contacts() const
{
	if (num_of_elem <= 0)
	{
		std::cout << "Your phonebook is empty." << std::endl;
		return (num_of_elem);
	}
	for (int i = 0; i < num_of_elem; i++)
	{
		std::cout << "index: " << i + 1 << std::endl;;
		std::cout << "first name: " << contacts[i].first_name << std::endl;
		std::cout << "last name: " << contacts[i].last_name << std::endl;
		std::cout << "nickname: " << contacts[i].nickname << std::endl;
		std::cout << "phone number: " << contacts[i].phone_number << std::endl;
		std::cout << "darkest_secret: " << contacts[i].darkest_secret << std::endl;
		std::cout << std::endl;
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
	std::cout << std::endl;
}
