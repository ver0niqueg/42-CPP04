/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:09:57 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 17:29:34 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass/Cat.hpp"
#include "DogClass/Dog.hpp"

int main() 
{
    // Création simple d'animaux
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << CYAN << "\n=== Making Sounds ===" << RST << std::endl;
    j->makeSound();
    i->makeSound();

    
    delete j;
    delete i;

    std::cout << CYAN << "\n=== Array of Animals ===" << RST << std::endl;
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int k = 0; k < SIZE; ++k) {
        if (k < SIZE / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << CYAN << "\n=== Make sounds from array ===" << RST << std::endl;
    for (int k = 0; k < SIZE; ++k)
        animals[k]->makeSound();

    std::cout << CYAN << "\n=== Test Brain deep copy with Dog ===" << RST << std::endl;
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "Eat bones");
    Dog dog2(*dog1); // deep copy
    dog2.getBrain()->setIdea(0, "Chase cats");

    std::cout << "dog1 idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    delete dog1;

    std::cout << CYAN << "\n=== Test multiple ideas with Dog ===" << RST << std::endl;
    Dog* dogA = new Dog();
    dogA->getBrain()->setIdea(0, "Eat bones");
    dogA->getBrain()->setIdea(1, "Sleep");
    dogA->getBrain()->setIdea(2, "Play fetch");

    Dog dogB(*dogA); // deep copy
	dogB.getBrain()->setIdea(0, "Take a nap");
    dogB.getBrain()->setIdea(1, "Chase cats");

    std::cout << "dogA idea[0]: " << dogA->getBrain()->getIdea(0) << std::endl;
    std::cout << "dogA idea[1]: " << dogA->getBrain()->getIdea(1) << std::endl;
	std::cout << "dogA idea[2]: " << dogA->getBrain()->getIdea(2) << std::endl;
    std::cout << "dogB idea[0]: " << dogB.getBrain()->getIdea(0) << std::endl;
    std::cout << "dogB idea[1]: " << dogB.getBrain()->getIdea(1) << std::endl;
	std::cout << "dogB idea[2]: " << dogB.getBrain()->getIdea(2) << std::endl;
    delete dogA;

    std::cout << CYAN << "\n=== Test Brain deep copy with Cat ===" << RST << std::endl;
    Cat* cat1 = new Cat();
    cat1->getBrain()->setIdea(0, "Chase mice");

    Cat cat2(*cat1);
    cat2.getBrain()->setIdea(0, "Climb trees");

    std::cout << "cat1 idea[0]: " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
    delete cat1;

	std::cout << CYAN << "\n=== Test shallow vs deep copy ===" << RST << std::endl;

    Dog basic;
    basic.getBrain()->setIdea(0, "Eat bones");

    Dog tmp = basic;
    tmp.getBrain()->setIdea(0, "Chase cats");

    std::cout << "tmp Brain idea[0]: " << tmp.getBrain()->getIdea(0) << std::endl;
    std::cout << "basic Brain idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;
    std::cout << "basic Brain idea[0] after tmp destroyed: " 
              << basic.getBrain()->getIdea(0) << std::endl;

    std::cout << CYAN << "\n=== Test deep copy with assignment operator ===" << RST << std::endl;
    Dog dog3;
    dog3.getBrain()->setIdea(0, "Guard the house");

    Dog dog4;
    dog4 = dog3;

    dog4.getBrain()->setIdea(0, "Dig holes");
    std::cout << "dog3 idea[0]: " << dog3.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog4 idea[0]: " << dog4.getBrain()->getIdea(0) << std::endl;

    std::cout << CYAN << "\n=== Deleting array ===" << RST << std::endl;
    for (int k = 0; k < SIZE; ++k)
        delete animals[k];

    return 0;
}