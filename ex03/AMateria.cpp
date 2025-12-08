#include "Interface.hpp"

AMateria::AMateria():
type_(""){
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const std::string& type):
type_(type){
	std::cout << "AMateria constructor called\n";
}

AMateria::~AMateria(){
	std::cout << "AMateria destructor called\n";
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria copy constructor called\n";
	this->type_ = other.type_;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria copy assignment operator called\n";
	if (this == &other)
		return (*this);
	this->type_ = other.type_;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return type_;
}
