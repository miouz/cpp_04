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
	if (m == NULL)
	{
		std::cerr << " try to equip an empty AMateria\n";
		return ;
	}
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (inventory_[i] == NULL)
		{
			inventory_[i] = m;
			std::cout << name_ << " equiped successfully at index " << i << "of inventory slot\n";
			return ;
		}	
	}
	std::cerr << name_ << "'s inventory is full, can't equipe more\n";
}

void Character::unequip(int idx)
{
	if (idx >= SLOT_MAX || idx < 0)
	{
		std::cerr << "index out of inventory range\n";
		return ;
	}
	if (inventory_[idx] == NULL)
	{
		std::cerr << "inventory at " << idx << " slot is empty, nothing to unequip\n";
		return ;
	}
	inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= SLOT_MAX || idx < 0)
	{
		std::cerr << "index out of inventory range\n";
		return ;
	}
	if (inventory_[idx] == NULL)
	{
		std::cerr << "inventory at " << idx << " slot is empty, nothing to use\n";
		return ;
	}
	inventory_[idx]->use(target);
	delete inventory_[idx];
}

AMateria* const Character::getInventory(int index) const
{
	if (index < 0 || index >= SLOT_MAX)
	{
		std::cerr << "index out of inventory's range\n";
		return NULL;
	}
	return inventory_[index];
}
