#ifndef AMATERIA_HPP_
# define AMATERIA_HPP_

#include "Interface.hpp"

class AMateria
{
	protected:
	std::string type_;
	// [...]
	public:
	AMateria(std::string const & type);
	virtual~AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif // !AMATERIA_HPP_
