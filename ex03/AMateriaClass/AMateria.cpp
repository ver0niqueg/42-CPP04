/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:40:26 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 13:55:24 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "../CharacterClass/ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << _type << " Materia has appeared in the realm!" << std::endl;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	std::cout << "AMateria copy constructor has been called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "AMateria assignment operator has been called." << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor has been called." << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

// fonction qui represente l'action de la Materia su un personnage (ICharacter)
void AMateria::use(ICharacter &target)
{
	(void)target;
}