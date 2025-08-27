/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:35:52 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/27 17:35:35 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "A dog just appeared !" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	type = copy.type;
	std::cout << "A twin of the dog just appeared !" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		type = other.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "The dog just left." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "* Wooooof ! Wooooof ! *" << std::endl;    
}

void Dog::setIdea(int index, const std::string &idea) {
    if (brain)
        brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    static std::string empty = "";
    return empty;
}