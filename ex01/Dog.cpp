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
	brain_ = new Brain;
	if (brain_ && other.brain_)
		*brain_ = *(other.brain_);
}

Dog& Dog::operator=(const Dog&other)
{
	if (this == &other)
		return (*this);
	if (brain_ && other.brain_)
		*brain_ = *(other.brain_);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf\n";
}

void Dog::setBrain(Brain* const brain)
{
	if (brain_ && brain)
		*brain_ = *brain;
	else
	 std::cerr << "the given brain is NULL\n";
}

Brain* Dog::getBrain()const
{
	return brain_;
}

