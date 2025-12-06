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

	void setIdeas(const std::string& idea, const int index);
	std::string getIdeas(int)const;
	void displayIdeas() const;
};

#endif // !BRAIN_HPP_
