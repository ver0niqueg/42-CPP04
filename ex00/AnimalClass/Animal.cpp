/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:21:15 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/26 21:17:48 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Undefined")
{
    std::cout << "An animal has been created." << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
    std::cout << "An animal just cloned itself." << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "An animal has disappeared" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "* Unrecognized animal sound *" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}