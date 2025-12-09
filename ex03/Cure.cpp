#include "Interface.hpp"

Cure::Cure():
 AMateria("cure"){
	std::cout << "Cure default constructor called\n";
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

Cure::Cure(const Cure& other):
	AMateria("cure")
{
	std::cout <<"Cure copy constructor called\n";
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout <<"Cure copy assignment operator called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* copy = new Cure(*this);
	if (copy == NULL)
		std::cerr << "clone Cure failed\n";
	return copy;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
