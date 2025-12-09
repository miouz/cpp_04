#include "Interface.hpp"

Ice::Ice():
 AMateria("ice"){
	std::cout << "Ice default constructor called\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

Ice::Ice(const Ice& other):
	AMateria("ice")
{
	std::cout <<"Ice copy constructor called\n";
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout <<"Ice copy assignment operator called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* copy = new Ice(*this);
	if (copy == NULL)
		std::cerr << "clone Ice failed\n";
	return copy;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << "*\n";
}
