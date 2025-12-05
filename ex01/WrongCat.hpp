#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat&other);

	void makeSound() const;
};
#endif // !WRONGCAT_HPP_
