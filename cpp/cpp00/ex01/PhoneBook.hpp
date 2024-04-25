#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <stdexcept>

typedef struct	s_info
{
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
}	t_info;

class	PhoneBook
{
	private:
		int			size;
		t_info		contacts[8];
	public:
		PhoneBook(const int sz);
		~PhoneBook();
		int		get_size() const;
		void	add_contact(const t_info *contact);
		void	delete_contact(int i);
		void	print_all_contacts() const;
		void	print_contact(int i) const;
};

#endif
