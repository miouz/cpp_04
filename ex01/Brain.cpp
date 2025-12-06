#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called\n";
	std::copy(&other.ideas_[0], &other.ideas_[100], this->ideas_);
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment constructor called\n";
	if (this == &other)
		return (*this);
	std::copy(&other.ideas_[0], &other.ideas_[100], this->ideas_);
	return *this;
}

void Brain::setIdeas(const std::string& idea, const int index)
{
	if (index <= 99 && index >= 0)
		ideas_[index] = idea;
	else
		std::cerr<< "index out of range\n";
}


std::string Brain::getIdeas(int index)const
{
	if (index > 99 || index < 0)
		std::cerr<< "index out of range\n";
	else
		index = 0;
	return ideas_[index];
}
