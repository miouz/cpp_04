#include "Cat.hpp"
#include "AAnimal.hpp"
#include <iostream>

Cat::Cat():
	AAnimal("Cat")
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
	AAnimal("Cat")
{
	std::cout << "Cat copy constructor called\n";
	brain_ = new Brain;
	if (brain_ && other.brain_)
		*brain_ = *(other.brain_);
}
Cat& Cat::operator=(const Cat&other)
{
	if (this == &other)
		return (*this);
	if (brain_ && other.brain_)
		*brain_ = *(other.brain_);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou\n";
}

void Cat::setBrain(Brain* const brain)
{
	if (brain_ && brain)
		*brain_ = *brain;
	else
	 std::cerr << "the given brain is NULL\n";
}

Brain* Cat::getBrain()const
{
	return brain_;
}

