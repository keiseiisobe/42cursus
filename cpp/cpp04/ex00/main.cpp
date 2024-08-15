#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->get_type() << " " << std::endl;
	std::cout << i->get_type() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

// WrongAnimal test
	std::cout << std::endl << "-----WrongAnimal test-----" << std::endl;
	const WrongAnimal* meta_2 = new WrongAnimal();
	const WrongAnimal* i_2 = new WrongCat();
	std::cout << i_2->get_type() << " " << std::endl;
	i_2->makeSound(); //will output the WrongAnimal sound!
	meta_2->makeSound();
	delete meta_2;
	delete i_2;
	std::cout << "--------------------------" << std::endl;
	return 0;
}

/* __attribute__((destructor)) */
/* static void destructor() { */
/*     system("leaks -q a.out"); */
/* } */
