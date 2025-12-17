#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iomanip>

int main()
{
	std::cout << "==========test from subject==========\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "==========test from mi==========\n";
	std::cout << "==========creat a character, equipe with 5 objects and deep copy it==========\n";
	Character* gustave = new Character("Gustave");
	Character* randomBadGuy = new Character("RandomBadGuy");
	AMateria* goodIce = new Ice[5];
	AMateria* badCure = new Cure[5];
	AMateria* scam = NULL;

	//test for equipe empty materia
	randomBadGuy->equip(scam);

	for(int i = 0; i < 5; i++)
	{
		if (i < 3)
			gustave->equip(&badCure[i]);
		else
		 	gustave->equip(&goodIce[i]);
	}
	Character* verso = new Character(*gustave);
	for(int i = 0; i < SLOT_MAX; i++)
	{
		std::cout << verso->getName() << " has "<< verso->getInventory(i)->getType() << " at inventory index " <<i << " \n";
	}
	std::cout << "\n==========the battle begins, Gustave is ready==========\n";
	//test for index out of range
	gustave->use(5, *randomBadGuy);

	gustave->use(3, *randomBadGuy);
	std::cout << "\nThe ground is so slippery that Gustave falls and drops 3 items he has\n";
	//test for index out of range
	gustave->unequip(4);

	gustave->unequip(3);
	gustave->unequip(2);
	gustave->unequip(1);
	std::cout << "\nGustave decides to use the only badCure he has\n";
	gustave->use(0, *gustave);
	std::cout << "\nGustave's hand shakes and drops the only item he has\n";
	gustave->unequip(0);
	std::cout << "\nGoodbye Gustave\n";
	delete[] goodIce;
	delete[] badCure;
	delete randomBadGuy;
	delete gustave;
	delete verso;
	return 0;
}
