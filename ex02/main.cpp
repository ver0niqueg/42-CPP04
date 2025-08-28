/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:52:18 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/28 15:01:33 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass/Cat.hpp"
#include "DogClass/Dog.hpp"

int main() 
{
    // === Création d'animaux via AAnimal ===
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << CYAN << "\n=== Making Sounds ===" << RST << std::endl;
    j->makeSound(); // Woof woof!
    i->makeSound(); // Meow

    // Suppression via pointeur de base (destructeur virtuel)
    delete j;
    delete i;

    // === Tableau d'animaux ===
    std::cout << CYAN << "\n=== Array of Animals ===" << RST << std::endl;
    const int SIZE = 4;
    AAnimal* animals[SIZE];

    for (int k = 0; k < SIZE; ++k) {
        if (k < SIZE / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << CYAN << "\n=== Make sounds from array ===" << RST << std::endl;
    for (int k = 0; k < SIZE; ++k)
        animals[k]->makeSound();

    // === Test Brain deep copy Dog ===
    std::cout << CYAN << "\n=== Test Brain deep copy with Dog ===" << RST << std::endl;
    Dog* dog1 = new Dog();
    dog1->setIdea(0, "Eat bones");
    Dog dog2(*dog1); // deep copy
    dog2.setIdea(0, "Chase cats");
    std::cout << "dog1 idea[0]: " << dog1->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;
    delete dog1;

    // === Test multiple ideas Dog ===
    std::cout << CYAN << "\n=== Test multiple ideas with Dog ===" << RST << std::endl;
    Dog* dogA = new Dog();
    dogA->setIdea(0, "Eat bones");
    dogA->setIdea(1, "Sleep");
    dogA->setIdea(2, "Play fetch");

    Dog dogB(*dogA); // deep copy
    dogB.setIdea(1, "Chase cats");

    std::cout << "dogA idea[0]: " << dogA->getIdea(0) << std::endl;
    std::cout << "dogA idea[1]: " << dogA->getIdea(1) << std::endl;
    std::cout << "dogB idea[1]: " << dogB.getIdea(1) << std::endl;
    std::cout << "dogA idea[2]: " << dogA->getIdea(2) << std::endl;
    std::cout << "dogB idea[2]: " << dogB.getIdea(2) << std::endl;
    delete dogA;

    // === Test Brain deep copy Cat ===
    std::cout << CYAN << "\n=== Test Brain deep copy with Cat ===" << RST << std::endl;
    Cat* cat1 = new Cat();
    cat1->setIdea(0, "Chase mice");

    Cat cat2(*cat1);
    cat2.setIdea(0, "Climb trees");

    std::cout << "cat1 idea[0]: " << cat1->getIdea(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getIdea(0) << std::endl;
    delete cat1;

    // === Test assignment operator ===
    std::cout << CYAN << "\n=== Test assignment operator ===" << RST << std::endl;
    Dog dog3;
    dog3.setIdea(0, "Guard the house");
    dog3.setIdea(1, "Run fast");
    dog3.setIdea(2, "Catch ball");

    Dog dog4;
    dog4 = dog3; // deep copy via opérateur=

    dog4.setIdea(0, "Dig holes");
    std::cout << "dog3 idea[0]: " << dog3.getIdea(0) << std::endl;
    std::cout << "dog4 idea[0]: " << dog4.getIdea(0) << std::endl;
    std::cout << "dog3 idea[1]: " << dog3.getIdea(1) << std::endl;
    std::cout << "dog4 idea[1]: " << dog4.getIdea(1) << std::endl;

    // === Suppression tableau ===
    std::cout << CYAN << "\n=== Deleting array ===" << RST << std::endl;
    for (int k = 0; k < SIZE; ++k)
        delete animals[k]; // destructeurs virtuels libèrent Brain*

    return 0;
}