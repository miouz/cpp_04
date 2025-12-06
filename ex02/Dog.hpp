#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	Brain* brain_;

	public:
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog&other);

	void setBrain(Brain* const brain);
	Brain* getBrain()const;

	void makeSound() const;
};
#endif // !DOG_HPP
