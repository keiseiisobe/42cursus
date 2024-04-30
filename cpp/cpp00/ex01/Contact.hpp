#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"

class	Contact
{
	private:
		t_info	contact;
		void	put_first_name(t_info *contact);
		void	put_last_name(t_info *contact);
		void	put_nickname(t_info *contact);
		void	put_phone_number(t_info *contact);
		void	put_darkest_secret(t_info *contact);
	public:
		void	put_all_fields_into_contact(t_info *contact);
};

bool	valid_name(const std::string first_name);
bool	valid_number(const std::string number);

#endif
