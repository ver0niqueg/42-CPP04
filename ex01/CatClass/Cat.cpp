/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:49:11 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/27 17:35:47 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "A cat just came to explore !" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	type = copy.type;
	std::cout << "The cat just cloned itself !" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		type = other.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "The cat has gone." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "* Meowww ! Moewww ! *" << std::endl;    
}

void Cat::setIdea(int index, const std::string &idea) {
    if (brain)
        brain->setIdea(index, idea);
}

const std::string &Cat::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    static std::string empty = "";
    return empty;
}