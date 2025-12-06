#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "==================test from the main.cpp of subject===============\n";
	//test from main in the subject
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}

	std::cout << "==================test asked in the subject===============\n";
	//test from subject
	{
		Animal* animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i >= 0 && i <= 4)
				animals[i] = new Dog; 
			else
	   			animals[i] = new Cat;
		}
		for (int b = 0; b < 10; b++)
		{
			animals[b]->makeSound();
			delete animals[b];
		}
	}

	std::cout << "==================my test for testing shallow copy===============\n";

	Brain*	badBrain = new Brain();
	Brain*	goodBrain = new Brain();
	// put ideas in each brain
	for (int i = 0; i < 100; i++)
	{
		badBrain->setIdeas("i'm bad dog\n", i);
		goodBrain->setIdeas("i'm good cat\n", i);
	}
	//test for brain copy constructor and copy assignment operator
	Brain*	positiveBrain = new Brain(*goodBrain);
	*positiveBrain = *badBrain;
	std::cout << "in positiveBrain:\n";
	positiveBrain->displayIdeas();
	std::cout << "in goodBrain:\n";
	goodBrain->displayIdeas();
	std::cout << "in badBrain:\n";
	badBrain->displayIdeas();

	// test for dog's deep copy	
	Dog* chiwawa = new Dog();
	Dog* husky = new Dog();

	chiwawa->setBrain(badBrain);
	husky->setBrain(goodBrain);
	
	Dog* chiba = new Dog(*husky);
	*chiwawa = *husky;
	std::cout << "in chiwawa's brain:\n";
	chiwawa->getBrain()->displayIdeas();
	std::cout << "in husky's brain:\n";
	husky->getBrain()->displayIdeas();
	std::cout << "in chiba's brain:\n";
	chiba->getBrain()->displayIdeas();

	delete goodBrain;
	delete badBrain;
	delete positiveBrain;
	delete chiwawa;
	delete husky;
	delete chiba;

	// test for cat's deep copy	
	Cat aNormalCat;

	Brain* randomCatBrain = new Brain;
	for (int i = 0; i < 100; i++)
		randomCatBrain->setIdeas("i need nobody i'm the best\n", i);

	aNormalCat.setBrain(randomCatBrain);
	Cat	moulinette(aNormalCat);
	
	std::cout << "in aNormalCat's brain:\n";
	aNormalCat.getBrain()->displayIdeas();
	std::cout << "in moulinette's brain:\n";
	moulinette.getBrain()->displayIdeas();

	delete randomCatBrain;

	return 0;
}
