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

void	PhoneBook::delete_contact(int i)
{
//	if (index < 0)
	for (; i > 0; i--)
		contacts[i] = contacts[i - 1];
	num_of_elem--;
}

void	PhoneBook::add_contact(const t_info *contact)
{
	try
	{
		num_of_elem++;
		if (num_of_elem > size)
			throw std::out_of_range("Notice: Out_of_range: delete oldest one");
	}
	catch(const std::out_of_range& oor)
	{
		delete_contact(size - 1);
	}
	contacts[0].index = contact->index;
	contacts[0].first_name = contact->first_name;
	contacts[0].last_name = contact->last_name;
	contacts[0].nickname = contact->nickname;
	contacts[0].phone_number = contact->phone_number;
	contacts[0].darkest_secret = contact->darkest_secret;
}

void	PhoneBook::print_all_contacts() const
{
	for (int i = 0; i < num_of_elem; i++)
	{
		std::cout << "index: " << contacts[i].index << std::endl;;
		std::cout << "first name: " << contacts[i].first_name << std::endl;
		std::cout << "last name: " << contacts[i].last_name << std::endl;
		std::cout << "nickname: " << contacts[i].nickname << std::endl;
		std::cout << "phone number: " << contacts[i].phone_number << std::endl;
		std::cout << "darkest_secret: " << contacts[i].darkest_secret << std::endl;
		std::cout << std::endl;
	}
}

void	PhoneBook::print_contact(int i) const
{
	std::cout << "index: " << contacts[i].index << std::endl;;
	std::cout << "first name: " << contacts[i].first_name << std::endl;
	std::cout << "last name: " << contacts[i].last_name << std::endl;
	std::cout << "nickname: " << contacts[i].nickname << std::endl;
	std::cout << "phone number: " << contacts[i].phone_number << std::endl;
	std::cout << "darkest_secret: " << contacts[i].darkest_secret << std::endl;
	std::cout << std::endl;
}
