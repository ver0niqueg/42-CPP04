/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:09:57 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/27 17:24:02 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass/Cat.hpp"
#include "DogClass/Dog.hpp"

int main() {
    // Création simple d'animaux
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << CYAN << "\n=== Making Sounds ===" << RST << std::endl;
    j->makeSound();
    i->makeSound();

    // Suppression via pointeur de base (virtual destructeur)
    delete j; // Dog::~Dog() + Brain::~Brain() appelés
    delete i; // Cat::~Cat() + Brain::~Brain() appelés

    std::cout << CYAN << "\n=== Array of Animals ===" << RST << std::endl;
    const int SIZE = 4;
    Animal* animals[SIZE];

    // Remplir moitié Dog, moitié Cat
    for (int k = 0; k < SIZE; ++k) {
        if (k < SIZE / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << CYAN << "\n=== Make sounds from array ===" << RST << std::endl;
    for (int k = 0; k < SIZE; ++k)
        animals[k]->makeSound();

    std::cout << CYAN << "\n=== Test Brain deep copy ===" << RST << std::endl;
    Dog* dog1 = new Dog();
    dog1->setIdea(0, "Eat bones");
    Dog dog2(*dog1); // deep copy
    dog2.setIdea(0, "Chase cats");
    std::cout << "dog1 idea[0]: " << dog1->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;
    delete dog1;

    std::cout << CYAN << "\n=== Deleting array ===" << RST << std::endl;
    for (int k = 0; k < SIZE; ++k)
        delete animals[k]; // destructeurs virtuels assurent la libération de Brain*

    return 0;
}