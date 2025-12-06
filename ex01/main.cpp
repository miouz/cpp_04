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
			if (i <= 0 && i <= 4)
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

		Animal* chiwawa = new Dog();
		Animal* husky = new Dog();
		Brain*	badBrain = new Brain();
		Brain*	humanBrain = new Brain();
	return 0;
}
