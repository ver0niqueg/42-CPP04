/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:47:53 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/02 13:07:35 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "A wrong cat just came out of nowhere !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	type = copy.type;
	std::cout << "Another exact same wrong cat appeared." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "A wrong cat just vanished." << std::endl;
}

void WrongCat::makeSound() const 
{
	std::cout << type << " : * Meuuuuuuuh * What?!" << std::endl;
}