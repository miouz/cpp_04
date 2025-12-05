#ifndef BRAIN_HPP_
# define BRAIN_HPP_

#include <string>

class	Brain
{
	std::string ideas_[100];

	public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
};

#endif // !BRAIN_HPP_
