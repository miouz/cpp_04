#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "==================test from the main.cpp of subject===============\n";
	//test from main in the subject
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}

	std::cout << "==================test asked in the subject===============\n";
	//test from subject
	{
		AAnimal* animals[10];
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

	std::cout << "==================test for AAnimal===============\n";
	{
		// AAnimal animal;
	}

	return 0;
}
