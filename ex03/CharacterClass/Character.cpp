/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:32:40 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 13:55:41 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _trashCount(0)
{
	std::cout << _name << " enters the battlefield!" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 50; i++)
		_trash[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name), _trashCount(0)
{
	std::cout << "A copy of " << _name << " has been created !" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		for (int i = 0; i < 50; i++)
		_trash[i] = NULL;
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
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		// vider ancienne trash
		for (int i = 0; i < _trashCount; i++)
			delete _trash[i];
		_trashCount = 0;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << _name << " retreats from the battlefield." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
	for (int i = 0; i < _trashCount; i++)
		delete _trash[i];
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m; // clone pour que le Character ait sa propre copie
			std::cout << _name << " equipped " << _inventory[i]->getType()
					  << " in slot " << i << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full !" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << _name << " unequipped " << _inventory[idx]->getType()
				  << " from slot " << idx << "!" << std::endl;
		_trash[_trashCount++] = _inventory[idx];  // garder la materia en mémoire
		_inventory[idx] = NULL; // objet toujours vivant pour éviter invalid read
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}