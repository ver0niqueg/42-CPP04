/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:53:12 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 13:56:01 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharacterClass/Character.hpp"
#include "AMateriaClass/MateriaSource.hpp"
#include "IceClass/Ice.hpp"
#include "CureClass/Cure.hpp"

int main()
{
	std::cout << CYAN << "=== Creating MateriaSource and learning Materias ===" << RST << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // ignored, inventory full

	std::cout << CYAN << "\n=== Creating Characters ===" << RST << std::endl;
	Character* jade = new Character("jade");
	Character* bob = new Character("bob");
	Character* alice = new Character("alice");

	std::cout << CYAN << "\n=== Equipping Materias ===" << RST << std::endl;
	AMateria* tmp;

	tmp = src->createMateria("ice");
	jade->equip(tmp);

	tmp = src->createMateria("cure");
	jade->equip(tmp);

	tmp = src->createMateria("fire"); // unknown type, returns nullptr
	jade->equip(tmp); // does nothing

	tmp = src->createMateria("cure");
	alice->equip(tmp);

	std::cout << CYAN << "\n=== Using Materias ===" << RST << std::endl;
	jade->use(0, *bob);  // Ice
	jade->use(1, *bob);  // Cure
	jade->use(2, *bob);  // nullptr, does nothing

	alice->use(0, *bob); // Cure

	std::cout << CYAN << "\n=== Testing unequip ===" << RST << std::endl;
	// save the unequipped Materia to delete it later
	jade->unequip(1);

	jade->use(1, *bob); // nothing happens

	std::cout << CYAN << "\n=== Testing deep copy of Character ===" << RST << std::endl;
	Character copyMe(*jade);
	copyMe.use(0, *bob);
	copyMe.use(1, *bob); // empty slot, nothing happens

	std::cout << CYAN << "\n=== Cleaning up ===" << RST << std::endl;
	delete bob;
	delete jade;
	delete alice;
	delete src;

	return 0;
}