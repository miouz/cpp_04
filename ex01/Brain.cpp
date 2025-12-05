#include "Brain.hpp"

Brain::Brain(){}

Brain::~Brain(){}

Brain::Brain(const Brain& other)
{
	std::copy(&other.ideas_[0], &other.ideas_[100], this->ideas_);
}

Brain& Brain::operator=(const Brain& other)
{
	if (this == &other)
		return (*this);
	std::copy(&other.ideas_[0], &other.ideas_[100], this->ideas_);
	return *this;
}
