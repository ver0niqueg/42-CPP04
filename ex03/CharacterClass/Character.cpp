/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:32:40 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/29 15:11:08 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    std::cout << _name << " is ready for adventure !" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name)
{
    std::cout << "A copy of " << _name << " has been created !" << std::endl;
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
            delete _inventory[i];
            _inventory[i] = NULL;
            // on peut delete car c'est un tableau de pointeur
        }
        // deep copy de the other inventaire
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i];
            else
                _inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << _name << " has left the adventure." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i];
        _inventory[i] = NULL;
    }
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            std::cout << _name << " equipped a materia in slot " << i << std::endl;
            return ;
        }
    }
    std::cout << _name << "'s inventory is full !" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        std::cout << _name << " unequipped materia from slot " << idx << std::endl;
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}