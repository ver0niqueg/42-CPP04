/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:22:39 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/29 16:12:12 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << _type << " has been generated successfully!" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    std::cout << "A copy of " << _type << " has been generated successfully!" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
        AMateria::operator=(other);
    std::cout << _type << " assignment operator has been called." << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << _type << " has been vanished." << std::endl;
}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}