#ifndef CAT_HPP_
# define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	Brain* brain_;

	public:
	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat&other);

	void makeSound() const;
};
#endif // !CAT_HPP_
