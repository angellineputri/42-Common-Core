/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:51:22 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/09 14:32:21 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void	testIce()
{
	std::cout << std::endl << MAGENTA << "=====[1] Testing Materia Ice=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor of ice" << RESET << std::endl;
	AMateria *ice = new Ice();
	std::cout << "type: " << ice->getType() << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy constructor of ice" << RESET << std::endl;
	AMateria *ice_copy_constructor = new Ice(*dynamic_cast<Ice *>(ice));
	std::cout << "memory address of ice: " << ice << std::endl;
	std::cout << "memory address of ice_copy_constructor: " << ice_copy_constructor << std::endl;
	std::cout << "type of ice_copy_constructor: " << ice_copy_constructor->getType() << std::endl;

	std::cout << std::endl << MAGENTA << "testing clone function of ice" << RESET << std::endl;
	AMateria *ice_clone = ice->clone();
	std::cout << "memory address of ice: " << ice << std::endl;
	std::cout << "memory address of ice_clone: " << ice_clone << std::endl;
	std::cout << "type of ice_clone: " << ice_clone->getType() << std::endl;

	std::cout << std::endl << MAGENTA << "testing use function of ice" << RESET << std::endl;
	ICharacter *bob = new Character("bob");
	ice->use(*bob);

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete ice;
	delete ice_copy_constructor;
	delete ice_clone;
	delete bob;	
}

void	testCure()
{
	std::cout << std::endl << MAGENTA << "=====[2] Testing Materia Cure=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor of cure" << RESET << std::endl;
	AMateria *cure = new Cure();
	std::cout << "type: " << cure->getType() << std::endl;

	std::cout << std::endl << MAGENTA << "testing copy constructor of cure" << RESET << std::endl;
	AMateria *cure_copy_constructor = new Cure(*dynamic_cast<Cure *>(cure));
	std::cout << "memory address of cure: " << cure << std::endl;
	std::cout << "memory address of cure_copy_constructor: " << cure_copy_constructor << std::endl;
	std::cout << "type of cure_copy_constructor: " << cure_copy_constructor->getType() << std::endl;

	std::cout << std::endl << MAGENTA << "testing clone function of cure" << RESET << std::endl;
	AMateria *cure_clone = cure->clone();
	std::cout << "memory address of cure: " << cure << std::endl;
	std::cout << "memory address of cure_clone: " << cure_clone << std::endl;
	std::cout << "type of cure_clone: " << cure_clone->getType() << std::endl;

	std::cout << std::endl << MAGENTA << "testing use function of cure" << RESET << std::endl;
	ICharacter *bob = new Character("bob");
	cure->use(*bob);

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete cure;
	delete cure_copy_constructor;
	delete cure_clone;
	delete bob;	
}

void	testCharacter()
{
	std::cout << std::endl << MAGENTA << "=====[3] Testing Character=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor" << RESET << std::endl;
	Character* bob = new Character("bob");
	Character* stuart = new Character("stuart");
	std::cout << "name: " << bob->getName() << std::endl;
	std::cout << "name: " << stuart->getName() << std::endl;

	std::cout << std::endl << MAGENTA << "testing equip()" << RESET << std::endl;
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	AMateria *anotherIce = new Ice();
	AMateria *anotherCure = new Cure();
	bob->equip(ice);
	bob->equip(cure);
	bob->equip(anotherIce);
	bob->equip(anotherCure);
	bob->equip(new Ice());
	
	std::cout << std::endl << MAGENTA << "testing unequip(), and use()" << RESET << std::endl;
	bob->unequip(2);
	bob->unequip(2);
	bob->use(0, *stuart);
	bob->use(1, *stuart);
	bob->unequip(0);
	bob->use(0, *stuart);
	bob->use(1, *stuart);

	std::cout << std::endl << MAGENTA << "testing copy constructor (address)" << RESET << std::endl;
	Character *bob_copy_constructor = new Character(*bob);
	std::cout << "memory address of bob: " << bob << std::endl;
	std::cout << "memory address of bob_copy_constructor: " << bob_copy_constructor << std::endl;
	
	std::cout << std::endl << MAGENTA << "testing copy constructor (value)" << RESET << std::endl;
	std::cout << "bob name: " << bob->getName() << std::endl;
	std::cout << "bob_copy_constructor name: " << bob->getName() << std::endl;
	bob_copy_constructor->use(1, *stuart);
	bob_copy_constructor->equip(ice);
	bob_copy_constructor->use(1, *stuart);
	bob->use(1, *stuart);
	bob_copy_constructor->unequip(1);

	std::cout << std::endl << MAGENTA << "testing copy assignment" << RESET << std::endl;
	Character	*bob_copy_assg = new Character("bob_copy_assg");
	bob_copy_assg->equip(ice);

	std::cout << std::endl << MAGENTA << "bob values" << RESET << std::endl;
	std::cout << "bob name: " << bob->getName() << std::endl;
	std::cout << "memory address of bob: " << bob << std::endl;
	bob->use(0, *stuart);
	bob->use(1, *stuart);

	std::cout << std::endl << MAGENTA << "bob_copy_assg values before copying" << RESET << std::endl;
	std::cout << "bob_copy_assg name before: " << bob_copy_assg->getName() << std::endl;
	std::cout << "memory address of bob_copy_assg before: " << bob_copy_assg << std::endl;
	bob_copy_assg->use(0, *stuart);

	*bob_copy_assg = *bob;

	std::cout << std::endl << MAGENTA << "bob_copy_assg values after copying" << RESET << std::endl;
	std::cout << "bob_copy_assg name after: " << bob_copy_assg->getName() << std::endl;
	std::cout << "memory address of bob_copy_assg after: " << bob_copy_assg << std::endl;
	bob_copy_assg->use(0, *stuart);
	bob_copy_assg->use(1, *stuart);
	AMateria *tmp = bob_copy_assg->getMateria(0);
	bob_copy_assg->unequip(0);

	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete anotherIce;
	delete anotherCure;
	delete tmp;
	delete stuart;
	delete bob;
	delete bob_copy_constructor;
	delete bob_copy_assg;
}

void	testMateriaSource()
{
	AMateria *tmp;

	std::cout << std::endl << MAGENTA << "=====[4] Testing MateriaSource=====" << RESET << std::endl;
	std::cout << MAGENTA << "testing constructor" << RESET << std::endl;
	MateriaSource* source = new MateriaSource();
	
	std::cout << std::endl << MAGENTA << "testing learnMateria and createMateria" << RESET << std::endl;
	source->learnMateria(NULL);
	source->learnMateria(new Ice());
	tmp = source->createMateria("Cure");
	for (int i = 0; i < 3; ++i)
	{
		if (i % 2 == 1)
			source->learnMateria(new Ice());
		else
			source->learnMateria(new Cure());
	}

	std::cout << std::endl << MAGENTA << "testing learnMateria if already full" << RESET << std::endl;
	source->learnMateria(new Ice());

	std::cout << std::endl << MAGENTA << "testing createMateria" << RESET << std::endl;
	tmp = source->createMateria("Ice");
	tmp = source->createMateria("Cure");
	tmp = source->createMateria("ice");
	std::cout << "created: " << tmp->getType() << std::endl;
	delete tmp;
	tmp = source->createMateria("cure");
	std::cout << "created: " << tmp->getType() << std::endl;
	delete tmp;

	std::cout << std::endl << MAGENTA << "testing copy constructor (address)" << RESET << std::endl;
	MateriaSource *src_copy_constructor = new MateriaSource(*source);
	std::cout << "memory address of source: " << source << std::endl;
	std::cout << "memory address of src_copy_constructor: " << src_copy_constructor << std::endl;
	
	std::cout << std::endl << MAGENTA << "testing copy constructor (value)" << RESET << std::endl;
	tmp = src_copy_constructor->createMateria("cure");
	std::cout << "created: " << tmp->getType() << std::endl;
	delete tmp;
	tmp = src_copy_constructor->createMateria("ice");
	std::cout << "created: " << tmp->getType() << std::endl;
	delete tmp;

	std::cout << std::endl << MAGENTA << "testing copy assignment" << RESET << std::endl;
	MateriaSource	*ice_source = new MateriaSource();
	ice_source->learnMateria(new Ice());

	MateriaSource	*src_copy_assg = new MateriaSource();
	src_copy_assg->learnMateria(new Cure());

	std::cout << std::endl << MAGENTA << "ice_source values" << RESET << std::endl;
	std::cout << "memory address of ice_source: " << ice_source << std::endl;
	tmp = ice_source->createMateria("cure");
	tmp = ice_source->createMateria("ice");
	std::cout << "created: " << tmp->getType() << std::endl;
	delete tmp;

	std::cout << std::endl << MAGENTA << "src_copy_assg values before copying" << RESET << std::endl;
	std::cout << "memory address of src_copy_assg before: " << src_copy_assg << std::endl;
	tmp = src_copy_assg->createMateria("cure");
	std::cout << "created: " << tmp->getType() << std::endl;
	delete tmp;
	tmp = src_copy_assg->createMateria("ice");

	
	std::cout << std::endl << MAGENTA << "src_copy_assg values after copying" << RESET << std::endl;
	*src_copy_assg = *ice_source;
	std::cout << "memory address of src_copy_assg after: " << src_copy_assg << std::endl;
	tmp = src_copy_assg->createMateria("cure");
	tmp = src_copy_assg->createMateria("ice");
	std::cout << "created: " << tmp->getType() << std::endl;
	delete tmp;
	
	std::cout << std::endl << MAGENTA << "destructor" << RESET << std::endl;
	delete source;
	delete src_copy_constructor;
	delete src_copy_assg;
	delete ice_source;
}

int	main()
{
	testIce();
	testCure();
	testCharacter();
	testMateriaSource();
	return (0);
}
