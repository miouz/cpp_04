#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain* brain_;

	public:
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog&other);

	void makeSound() const;
};
#endif // !DOG_HPP
