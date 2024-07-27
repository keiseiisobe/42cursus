#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	return 0;
}
/*
__attribute__((destructor))
static void	destructor()
{
	system("leaks -q a.out");
}
*/
