/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:55:53 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 15:11:49 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogClass/Dog.hpp"
#include "CatClass/Cat.hpp"
#include "WrongCatClass/WrongCat.hpp"

int main()
{
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
wrongCat->makeSound();
wrongMeta->makeSound();

delete wrongMeta;
delete wrongCat;

return 0;
}