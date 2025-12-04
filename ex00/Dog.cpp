#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog():
	Animal("DOG")
{
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog()

