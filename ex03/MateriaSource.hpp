#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"
#define SLOT_MAX 4

class MateriaSource : public IMateriaSource
{
	AMateria*	inventory_[SLOT_MAX];

	public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);

	const AMateria* getInventory(int index) const;

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif // !MATERIASOURCE_HPP_
