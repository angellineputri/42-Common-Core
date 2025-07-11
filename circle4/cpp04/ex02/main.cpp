/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:50:29 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/09 10:30:18 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define DONT_PRINT_MSG 0
#define PRINT_MSG 1

void	testAnimal()
{
	std::cout << std::endl << MAGENTA << "=====[1] Test Animal=====" << RESET << std::endl;
	std::cout << MAGENTA << "the animal function is now an abstract class and cant be instantiate" << RESET << std::endl;
	// Animal	animalStack;
	// Animal*	animalHeap = new Animal();
}

void	testBrain()
{
	std::cout << std::endl << MAGENTA << "=====[2] Test Brain=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor" << RESET << std::endl;
	Brain *brain = new Brain();

	std::cout << std::endl << MAGENTA << "testing addIdea function" << RESET << std::endl;
	brain->addIdea("first idea", PRINT_MSG);
	brain->addIdea("another idea", PRINT_MSG);

	std::cout << std::endl << MAGENTA << "testing getIdea function" << RESET << std::endl;
	std::cout << "idea[0]: " << brain->getIdea(0) << std::endl;
	std::cout << "idea[1]: " << brain->getIdea(1) << std::endl;
	std::cout << "idea[2]: " << brain->getIdea(2) << std::endl;
	std::cout << "idea[5]: " << brain->getIdea(99) << std::endl;
	std::cout << "idea[100]: " << brain->getIdea(100) << std::endl;
	std::cout << "idea[-1]: " << brain->getIdea(-1) << std::endl;

	std::cout << std::endl << MAGENTA << "fill the brain with ideas until its full" << RESET << std::endl;
	for (int i = 0; i < 98; ++i)
		brain->addIdea("idea??", DONT_PRINT_MSG);

	std::cout << std::endl << MAGENTA << "add idea when its already full" << RESET << std::endl;
	brain->addIdea("can i be added :(", PRINT_MSG);

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete brain;
}

void	testDog()
{
	std::cout << std::endl << MAGENTA << "=====[3] Test Dog=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor" << RESET << std::endl;
	Dog* dog = new Dog();

	std::cout << std::endl << MAGENTA << "testing addIdea and getIdea of dog's brain" << RESET << std::endl;
	dog->getBrain()->addIdea("im hungry", PRINT_MSG);
	std::cout << "dog's idea[0]: " << dog->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy constructor" << RESET << std::endl;
	Dog* dog_copy_constructor = new Dog(*dog);

	std::cout << std::endl << MAGENTA << "testing copy constructor (address)" << RESET << std::endl;
	std::cout << "memory address of dog: " << dog << std::endl;
	std::cout << "memory address of dog_copy_constructor: " << dog_copy_constructor << std::endl;
	std::cout << "memory address of dog's brain: " << dog->getBrain() << std::endl;
	std::cout << "memory address of dog_copy_constructor's brain: " << dog_copy_constructor->getBrain() << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy constructor (values)" << RESET << std::endl;
	std::cout << "dog's idea[0]: " << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog_copy_constructor's idea[0]: " << dog_copy_constructor->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy assignment" << RESET << std::endl;	
	Dog	dog_copy_assg;
	dog_copy_assg.getBrain()->addIdea("im full", PRINT_MSG);

	std::cout << std::endl << MAGENTA << "dog's address and value" << RESET << std::endl;	
	std::cout << "memory address of dog: " << dog << std::endl;
	std::cout << "memory address of dog's brain: " << dog->getBrain() << std::endl;
	std::cout << "dog's idea[0]: " << dog->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "dog_copy_assg's address and value before the copy" << RESET << std::endl;	
	std::cout << "memory address of dog_copy_assg before: " << &dog_copy_assg << std::endl;
	std::cout << "memory address of dog_copy_assg's brain before: " << dog_copy_assg.getBrain() << std::endl;
	std::cout << "dog_copy_assg's idea[0] before: " << dog_copy_assg.getBrain()->getIdea(0) << std::endl;
	
	std::cout << std::endl << MAGENTA << "dog_copy_assg's address and value after the copy" << RESET << std::endl;	
	dog_copy_assg = *dog;
	std::cout << "memory address of dog_copy_assg after: " << &dog_copy_assg << std::endl;
	std::cout << "memory address of dog_copy_assg's brain after: " << dog_copy_assg.getBrain() << std::endl;
	std::cout << "dog_copy_assg's idea[0] after: " << dog_copy_assg.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete dog;
	delete dog_copy_constructor;
}

void	testCat()
{
	std::cout << std::endl << MAGENTA << "=====[4] Test Cat=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor" << RESET << std::endl;
	Cat* cat = new Cat();

	std::cout << std::endl << MAGENTA << "testing addIdea and getIdea of cat's brain" << RESET << std::endl;
	cat->getBrain()->addIdea("im hungry", PRINT_MSG);
	std::cout << "cat's idea[0]: " << cat->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy constructor" << RESET << std::endl;
	Cat* cat_copy_constructor = new Cat(*cat);

	std::cout << std::endl << MAGENTA << "testing copy constructor (address)" << RESET << std::endl;
	std::cout << "memory address of cat: " << cat << std::endl;
	std::cout << "memory address of cat_copy_constructor: " << cat_copy_constructor << std::endl;
	std::cout << "memory address of cat's brain: " << cat->getBrain() << std::endl;
	std::cout << "memory address of cat_copy_constructor's brain: " << cat_copy_constructor->getBrain() << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy constructor (values)" << RESET << std::endl;
	std::cout << "cat's idea[0]: " << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "cat_copy_constructor's idea[0]: " << cat_copy_constructor->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy assignment" << RESET << std::endl;	
	Cat	cat_copy_assg;
	cat_copy_assg.getBrain()->addIdea("im full", PRINT_MSG);

	std::cout << std::endl << MAGENTA << "cat's address and value" << RESET << std::endl;	
	std::cout << "memory address of cat: " << cat << std::endl;
	std::cout << "memory address of cat's brain: " << cat->getBrain() << std::endl;
	std::cout << "cat's idea[0]: " << cat->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "cat_copy_assg's address and value before the copy" << RESET << std::endl;	
	std::cout << "memory address of cat_copy_assg before: " << &cat_copy_assg << std::endl;
	std::cout << "memory address of cat_copy_assg's brain before: " << cat_copy_assg.getBrain() << std::endl;
	std::cout << "cat_copy_assg's idea[0] before: " << cat_copy_assg.getBrain()->getIdea(0) << std::endl;
	
	std::cout << std::endl << MAGENTA << "cat_copy_assg's address and value after the copy" << RESET << std::endl;	
	cat_copy_assg = *cat;
	std::cout << "memory address of cat_copy_assg after: " << &cat_copy_assg << std::endl;
	std::cout << "memory address of cat_copy_assg's brain after: " << cat_copy_assg.getBrain() << std::endl;
	std::cout << "cat_copy_assg's idea[0] after: " << cat_copy_assg.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete cat;
	delete cat_copy_constructor;
}

int	main()
{
	testAnimal();
	testBrain();
	testDog();
	testCat();
	return (0);
}
