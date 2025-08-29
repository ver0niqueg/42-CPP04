/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:18:07 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/29 14:46:43 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _storage[i] = NULL;
    std::cout << "MateriaSource generated." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy._storage[i])
            _storage[i] = copy._storage[i]->clone();
        else
            _storage[i] = NULL;
    }
    std::cout << "A copy of MateriaSource generated." << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        // supprimer l'ancien storage
        for (int i = 0; i < 4; i++)
        {
            delete _storage[i];
            _storage[i] = NULL;
        }
        // deep copy
        for (int i = 0; i < 4; i++)
        {
            if (other._storage[i])
                _storage[i] = other._storage[i]->clone();
            else
                _storage[i] = NULL; 
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete _storage[i];
        _storage[i] = NULL;
    }
    std::cout << "MateriaSource is destroyed." << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (_storage[i] == NULL)
        {
            _storage[i] = m->clone();
            std::cout << "Materia learned in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource is full, cannot learn more." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_storage[i] && _storage[i]->getType() == type)
            return (_storage[i]->clone());
    }
    return NULL;
}