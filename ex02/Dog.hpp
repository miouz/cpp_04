#ifndef DOG_HPP_
# define DOG_HPP_

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
