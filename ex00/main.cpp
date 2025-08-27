/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:55:53 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/27 15:45:23 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogClass/Dog.hpp"
#include "CatClass/Cat.hpp"
#include "WrongCatClass/WrongCat.hpp"

int main()
{
	// test le polymorphisme grace a virtual ~Animal() et makeSound()
std::cout << CYAN << "=== Correct Animals ===" << RST << std::endl;
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

i->makeSound();
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;

std::cout << CYAN << "\n=== Wrong Animals ===" << RST << std::endl;
const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();

std::cout << wrongCat->getType() << " " << std::endl;
wrongCat->makeSound();  // wrong animal sound
wrongMeta->makeSound(); // still wrong animal sound

delete wrongMeta;
delete wrongCat; // le destructeur de WrongCat n'est pas appelé car WrongAnimal::~WrongAnimal() n'est pas virtual
// mais pas de leak car pas d'allocation dynamique interne car type est detruit par WrongAnimal et WrongCat n'a pas d'autres allocations
// il aurait fallu mettre virtual dans le destructeur de WrongAnimal

return 0;
}