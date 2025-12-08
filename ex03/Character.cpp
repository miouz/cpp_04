#include "Interface.hpp"

Character::Character():
	ICharacter()
{
	std::cout << "Character default constructor called\n";
	name_ = "";
	for(int i = 0; i < SLOT_MAX; i++)
		inventory_[i] = NULL;
}

Character::Character(const std::string& name):
	ICharacter()
{
	std::cout << "Character constructor called\n";
	name_ = name;
	for(int i = 0; i < SLOT_MAX; i++)
		inventory_[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character deconstructor called\n";
	for(int i = 0; i < SLOT_MAX; i++)
	{
		delete inventory_[i];
		inventory_[i] = NULL;
	}
}

Character::Character(const Character& other):
	ICharacter()
{
	std::cout << "Character copy constructor called\n";
	name_ = other.name_;
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (other.inventory_[i])
		{
			delete this->inventory_[i];
			this->inventory_[i] = other.inventory_[i]->clone();
		}
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character copy assignment called\n";
	if (this == &other)
		return *this;
	this->name_ = other.name_;
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (other.inventory_[i])
		{
			delete this->inventory_[i];
			this->inventory_[i] = other.inventory_[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return name_;
}

void Character::equip(AMateria* m)
{
	
}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}
