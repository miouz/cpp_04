#include "Animal.hpp"
#include <iostream>

Animal::Animal():
type_("")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string& type):
type_(type)
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& other):
type_(other.type_)
{
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment called\n";
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

void Animal::makeSound()
{
	std::cout << "Animal's makeSound func called\n";
}
