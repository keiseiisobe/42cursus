#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
//	Animal	a;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	Animal	*animals[10];
	for (int i = 0;i < 5;i++)
	{
		animals[i] = new Dog();
	}
	for (int i = 5;i < 10;i++)
	{
		animals[i] = new Cat();
	}
	for (int i = 0;i < 10;i++)
	{
		delete animals[i];
	}

	// Checking deep copy
	Dog	*d1 = new Dog();
	Dog	*d2 = new Dog(*d1);
	delete d1;
	delete d2;
	Dog	*d3 = new Dog();
	Dog	*d4 = new Dog();
	*d3 = *d4;
	delete d3;
	delete d4;
	Cat	*c1 = new Cat();
	Cat	*c2 = new Cat(*c1);
	delete c1;
	delete c2;
	Cat	*c3 = new Cat();
	Cat	*c4 = new Cat();
	*c3 = *c4;
	delete c3;
	delete c4;
	return 0;
}

/* __attribute__((destructor)) */
/* static void	destructor() */
/* { */
/* 	system("leaks -q a.out"); */
/* } */
