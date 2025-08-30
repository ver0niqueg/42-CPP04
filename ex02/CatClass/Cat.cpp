/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:49:11 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 17:11:43 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "../BrainClass/Brain.hpp"

Cat::Cat() : AAnimal()
{
	type = "Cat";
	brain = new Brain(); // allouer Brain
	std::cout << "A cat just came to explore !" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	type = copy.type;
	brain = new Brain(*copy.brain); // deep copy
	std::cout << "The cat just cloned itself !" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		type = other.type;
		if (brain)
			delete brain; // supprimer l'ancien Brain
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "The cat has gone." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "* Meowww ! Moewww ! *" << std::endl;    
}

Brain *Cat::getBrain() const
{
	return (brain);
}