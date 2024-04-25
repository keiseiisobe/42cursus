#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook	book(8);
	t_info		contact;

	Contact	c;
	c.put_all_contact_fields();
	for (int i = 0; i < 15; i++)
	{
		contact.index = i;
		contact.first_name = "keisei";
		contact.last_name = "isobe";
		contact.nickname = "kisobe";
		contact.phone_number = "08011112222";
		contact.darkest_secret = "address:...";
		book.add_contact(&contact);
	}
	book.delete_contact(4);
	book.print_all_contacts();
	book.print_contact(1);
	return 0;
}
