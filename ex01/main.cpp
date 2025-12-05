#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Animal* h = new Dog();
	Animal* q = new Dog();
	*h = *q;
	delete q;
	delete h;
	return 0;
}
