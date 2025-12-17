#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource():
	IMateriaSource()
{
	// std::cout << "MateriaSource default constructor called\n";
	for(int i = 0; i < SLOT_MAX; i++)
		inventory_[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called\n";
	for(int i = 0; i < SLOT_MAX; i++)
	{
		delete inventory_[i];
		inventory_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other):
	IMateriaSource()
{
	// std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (other.inventory_[i])
			this->inventory_[i] = other.inventory_[i]->clone();
		else
	  		inventory_[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	// std::cout << "MateriaSource copy assignment called\n";
	if (this == &other)
		return *this;
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (other.inventory_[i])
		{
			delete this->inventory_[i];
			this->inventory_[i] = other.inventory_[i]->clone();
		}
	}
	return (*this);
}

const AMateria* MateriaSource::getInventory(int index) const
{
	if (index < 0 || index >= SLOT_MAX)
	{
		std::cerr << "index out of inventory's range\n";
		return NULL;
	}
	return inventory_[index];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << " try to learn an empty AMateria\n";
		return ;
	}
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (inventory_[i] == NULL)
		{
			inventory_[i] = m->clone();
			std::cout << m->getType()<< " is learned successfully at index " << i << " of inventory slot\n";
			delete m;
			return ;
		}	
	}
	std::cerr << "inventory is full, can't learn more\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (inventory_[i])
		{
			if (inventory_[i]->getType() == type)
				return inventory_[i]->clone();
		}
	}
	std::cerr << "type is not recognized by MateriaSource\n";
	return NULL;
}
