#include "Serializer.hpp"

int	main()
{
	string	name[] = {"ken", "emma", "anne", "taro", "takashi",
					"william", "james", "olivia", "oliver", "mia"};
	int	age[] = {11, 13, 15, 17, 19, 21, 12, 14, 16, 18};
	string	country[] = {"japan", "us", "uk", "canada", "france",
						"korea", "china", "germany", "brazil", "egypt"};

	for (int i = 0;i < 10;i++)
	{
		Data	d(name[i], age[i], country[i]);
		uintptr_t	ptr = Serializer::serialize(&d);
		Data	*d_ = Serializer::deserialize(ptr);
		if (d_ != &d || d_->name != name[i] || d_->age != age[i] || d_->country != country[i])
		{
			std::cout << "Serialization failed at index " << i << std::endl;
			return 0;
		}
	}
	std::cout << "All serialization successed!" << std::endl;
	return 0;
}
