/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:32:40 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/28 21:02:55 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    std::cout << _name << "is ready for adventure !" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name)
{
    std::cout << "A copy of " << _name << "has been created !" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        _name = other._name;
        // liberer l'ancien inventaire
        for (int i = 0; i < 4; i++)
        {
            delete 
            // on peut delete car c'est un tableau de pointeur
        }
    }
}