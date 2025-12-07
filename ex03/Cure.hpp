#ifndef CURE_HPP_
#define CURE_HPP_

#include "Interface.hpp"

class Cure: public AMateria
{
	public:
	Cure();
	~Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);

	AMateria* clone() const;
	void use(ICharacter& target);

};
#endif // !CURE_HPP_
