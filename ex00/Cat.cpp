#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat():
	Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat& other):
	Animal("Cat")
{
	std::cout << "Cat copy constructor called\n";
	type_ = other.type_;
}
Cat& Cat::operator=(const Cat&other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou\n";
}

