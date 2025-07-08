/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:49:21 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:49:22 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	testAnimal()
{
	std::cout << std::endl << MAGENTA << "=====[1] Test Animal=====" << RESET << std::endl;

	std::cout << MAGENTA << "testing constructor, type, and makeSound" << RESET << std::endl;
	const Animal* animal = new Animal();
	std::cout << animal->getType() << std::endl;
	animal->makeSound();

	std::cout << std::endl << MAGENTA << "testing copy constructor" << RESET << std::endl;
	Animal* animal_copy_constructor = new Animal(*animal);
	std::cout << "memory address of animal: " << animal << std::endl;
	std::cout << "memory address of animal_copy_constructor: " << animal_copy_constructor << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy assignment" << RESET << std::endl;
	Animal	animal_copy_assg;
	std::cout << "memory address of animal: " << animal << std::endl;
	std::cout << "memory address of animal_copy_assg before: " << &animal_copy_assg << std::endl;
	animal_copy_assg = *animal;
	std::cout << "memory address of animal_copy_assg after: " << &animal_copy_assg << std::endl;

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete animal;
	delete animal_copy_constructor;
}

void	testDog()
{
	std::cout << std::endl << MAGENTA << "=====[2] Test Dog=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor, type, and makeSound of dog animal pointer" << RESET << std::endl;
	const Animal* dog_animalptr = new Dog();
	std::cout << dog_animalptr->getType() << std::endl;
	dog_animalptr->makeSound();

	std::cout << std::endl << MAGENTA << "testing constructor, type, and makeSound of dog using dog pointer" << RESET << std::endl;
	const Dog* dog = new Dog();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();

	std::cout << std::endl << MAGENTA << "testing copy constructor" << RESET << std::endl;
	Dog* dog_copy_constructor = new Dog(*dog);
	std::cout << "memory address of dog: " << dog << std::endl;
	std::cout << "memory address of dog_copy_constructor: " << dog_copy_constructor << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy assignment" << RESET << std::endl;
	Dog	dog_copy_assg;
	std::cout << "memory address of dog: " << dog << std::endl;
	std::cout << "memory address of dog_copy_assg before: " << &dog_copy_assg << std::endl;
	dog_copy_assg = *dog;
	std::cout << "memory address of dog_copy_assg after: " << &dog_copy_assg << std::endl;

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete dog_animalptr;
	delete dog;
	delete dog_copy_constructor;
}

void	testCat()
{
	std::cout << std::endl << MAGENTA << "=====[3] Test Cat=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor, type, and makeSound of cat animal pointer" << RESET << std::endl;
	const Animal* cat_animalptr = new Cat();
	std::cout << cat_animalptr->getType() << std::endl;
	cat_animalptr->makeSound();

	std::cout << std::endl << MAGENTA << "testing constructor, type, and makeSound of cat using cat pointer" << RESET << std::endl;
	const Cat* cat = new Cat();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();

	std::cout << std::endl << MAGENTA << "testing copy constructor" << RESET << std::endl;
	Cat* cat_copy_constructor = new Cat(*cat);
	std::cout << "memory address of cat: " << cat << std::endl;
	std::cout << "memory address of cat_copy_constructor: " << cat_copy_constructor << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy assignment" << RESET << std::endl;
	Cat	cat_copy_assg;
	std::cout << "memory address of cat: " << cat << std::endl;
	std::cout << "memory address of cat_copy_assg before: " << &cat_copy_assg << std::endl;
	cat_copy_assg = *cat;
	std::cout << "memory address of cat_copy_assg after: " << &cat_copy_assg << std::endl;

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete cat_animalptr;
	delete cat;
	delete cat_copy_constructor;
}

void	testWrong()
{
	std::cout << std::endl << MAGENTA << "=====[4] Test Difference of WrongCat used as WrongAnimal and WrongCat used as WrongCat=====" << RESET << std::endl;
	const WrongAnimal* wrongCat_wrongAnimal = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();

	std::cout << std::endl << MAGENTA << "check the type" << RESET << std::endl;
	std::cout << "type of wrongCat used as wrongAnimal: " << wrongCat_wrongAnimal->getType() << std::endl;
	std::cout << "type of wrongCat used as wrongCat: " << wrongCat->getType() << std::endl;

	std::cout << std::endl << MAGENTA << "check the sound" << RESET << std::endl;
	std::cout << "sound of wrongCat used as wrongAnimal: ";
	wrongCat_wrongAnimal->makeSound();
	std::cout << "sound of wrongCat used as wrongCat";
	wrongCat->makeSound();

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete wrongCat_wrongAnimal;
	delete wrongCat;
}

int	main()
{
	testAnimal();
	testDog();
	testCat();
	testWrong();
	return (0);
}
