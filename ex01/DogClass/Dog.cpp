/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:35:52 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 16:02:40 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "../BrainClass/Brain.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "A dog just appeared !" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	type = copy.type;
	brain = new Brain(*copy.brain);
	std::cout << "A twin of the dog just appeared !" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
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

Dog::~Dog()
{
	delete brain;
	std::cout << "The dog just left." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "* Wooooof ! Wooooof ! *" << std::endl;    
}

Brain *Dog::getBrain() const
{
	return (brain);
}