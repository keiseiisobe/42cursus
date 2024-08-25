#pragma once

#include <string>
#include <iostream>

using std::string;
typedef unsigned long uintptr_t;

struct	Data
{
	Data(string d_name, int d_age, string d_country);
	string	name;
	int			age;
	string	country;
};

class	Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer&	operator=(const Serializer&);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
