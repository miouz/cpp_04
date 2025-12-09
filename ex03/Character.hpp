#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "ICharacter.hpp"
#define	SLOT_MAX 4

class Character: public ICharacter
{
	std::string name_;
	AMateria* inventory_[SLOT_MAX];

	public:
	Character();
	Character(const std::string& name);
	~Character();
	Character(const Character& other);
	Character& operator=(const Character& other);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif // !CHARACTER_HPP_
