#ifndef ICE_HPP_
#define ICE_HPP_

#include "Interface.hpp"

class Ice: public AMateria
{
	public:
	Ice();
	~Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);

	AMateria* clone() const = 0;
	void use(ICharacter& target);
};

#endif // !ICE_HPP_
