#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat():
	Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
	brain_ = new Brain;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete brain_;
}

Cat::Cat(const Cat& other):
	Animal("Cat")
{
	std::cout << "Cat copy constructor called\n";
	type_ = other.type_;
	*brain_ = *(other.brain_);
}
Cat& Cat::operator=(const Cat&other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	*brain_ = *(other.brain_);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou\n";
}

void Cat::setBrain(Brain* const brain)
{
	brain_ = brain;
}

Brain* Cat::getBrain()const
{
	return brain_;
}

