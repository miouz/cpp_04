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

	//getter and setter
	const std::string& getType() const;
	void setType(const std::string& type);

	 virtual void makeSound(void) const;
};
#endif // !ANIMAL_HPP_
