#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal
{
	protected:
	std::string type_;

	public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal&other);
	~WrongAnimal();

	//getter and setter
	const std::string& getType() const;
	void setType(const std::string& type);

	void makeSound(void) const;
};
#endif // !WRONGANIMAL_HPP_
