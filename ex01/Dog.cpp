#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog():
	Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
	brain_ = new Brain;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete brain_;
}

Dog::Dog(const Dog& other):
	Animal("Dog")
{
	std::cout << "Dog copy constructor called\n";
	type_ = other.type_;
	*brain_ = *(other.brain_);
}
Dog& Dog::operator=(const Dog&other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	delete brain_;
	*brain_ = *(other.brain_);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf\n";
}

