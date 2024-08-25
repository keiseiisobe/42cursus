#include "Serializer.hpp"

Data::Data(string d_name, int d_age, string d_country)
	: name(d_name), age(d_age), country(d_country)
{
}

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer&)
{
}

Serializer&	Serializer::operator=(const Serializer&)
{
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
