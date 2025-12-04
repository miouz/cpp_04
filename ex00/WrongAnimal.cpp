#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal():
type_("")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string& type):
type_(type)
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other):
type_(other.type_)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment called\n";
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal's makeSound func called\n";
}


const std::string& WrongAnimal::getType() const
{
	return this->type_;
}

void WrongAnimal::setType(const std::string& type)
{
	this->type_ = type;
}
