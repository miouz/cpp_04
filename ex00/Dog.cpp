#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog():
	Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog& other):
	Animal("Dog")
{
	std::cout << "Dog copy constructor called\n";
	type_ = other.type_;
}
Dog& Dog::operator=(const Dog&other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf\n";
}

