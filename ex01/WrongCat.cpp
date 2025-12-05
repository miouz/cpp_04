#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat():
	WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat& other):
	WrongAnimal("WrongCat")
{
	std::cout << "WrongCat copy constructor called\n";
	type_ = other.type_;
}
WrongCat& WrongCat::operator=(const WrongCat&other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Miaou Miaou\n";
}

