/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:49:11 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/31 13:14:12 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "../BrainClass/Brain.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "A cat just came to explore !" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	type = copy.type;
	brain = new Brain(*copy.brain);
	std::cout << "The cat just cloned itself !" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		type = other.type;
		if (brain)
			delete brain;
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