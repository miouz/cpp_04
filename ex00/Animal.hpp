#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal
{
	protected:
	std::string type_;

	public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	Animal& operator=(const Animal&other);
	~Animal();
};
#endif // !ANIMAL_HPP_
