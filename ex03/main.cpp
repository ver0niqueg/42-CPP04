/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:53:12 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/29 15:04:02 by vgalmich         ###   ########.fr       */
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
    src->learnMateria(new Ice());  // duplicate type
    src->learnMateria(new Cure()); // max 4
    src->learnMateria(new Ice());  // should be ignored, inventory full

    std::cout << CYAN << "\n=== Creating Characters ===" << RST << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    ICharacter* alice = new Character("alice");

    std::cout << CYAN << "\n=== Equipping Materias ===" << RST << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire"); // type unknown, should return NULL
    me->equip(tmp);                    // equip NULL should do nothing

    tmp = src->createMateria("cure");
    alice->equip(tmp);

    std::cout << CYAN << "\n=== Using Materias ===" << RST << std::endl;
    me->use(0, *bob);  // Ice
    me->use(1, *bob);  // Cure
    me->use(2, *bob);  // NULL, does nothing

    alice->use(0, *bob); // Cure

    std::cout << CYAN << "\n=== Testing unequip ===" << RST << std::endl;
    me->unequip(1);  // Cure removed
    me->use(1, *bob); // should do nothing

    std::cout << CYAN << "\n=== Testing deep copy of Character ===" << RST << std::endl;
    Character copyMe(*static_cast<Character*>(me));
    copyMe.use(0, *bob);  // Ice
    copyMe.use(1, *bob);  // empty slot, does nothing

    std::cout << CYAN << "\n=== Cleaning up ===" << RST << std::endl;
    delete bob;
    delete me;
    delete alice;
    delete src;

    return 0;
}