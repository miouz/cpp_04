#ifndef AANIMAL_HPP_
#define AANIMAL_HPP_

#include <string>

class AAnimal
{
	protected:
	std::string type_;

	public:
	AAnimal();
	AAnimal(const std::string& type);
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal&other);
	virtual ~AAnimal();

	//getter and setter
	const std::string& getType() const;
	void setType(const std::string& type);

	 virtual void makeSound(void) const = 0;
};
#endif // !ANIMAL_HPP_
