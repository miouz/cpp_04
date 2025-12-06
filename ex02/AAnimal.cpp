#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal():
type_("")
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const std::string& type):
type_(type)
{
	std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(const AAnimal& other):
type_(other.type_)
{
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal copy assignment called\n";
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal's makeSound func called\n";
}


const std::string& AAnimal::getType() const
{
	return this->type_;
}

void AAnimal::setType(const std::string& type)
{
	this->type_ = type;
}
