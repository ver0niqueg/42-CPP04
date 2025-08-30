/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:18:07 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 18:05:32 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_storage[i] = NULL;
	std::cout << "MateriaSource is ready to teach new Materias!" << std::endl;
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
		for (int i = 0; i < 4; i++)
		{
			delete _storage[i];
			_storage[i] = NULL;
		}
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
	std::cout << "MateriaSource has been dismantled." << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_storage[i] == NULL)
		{
			_storage[i] = m;
			std::cout << _storage[i]->getType() << " Materia has been mastered and stored in slot " << i << "!" << std::endl;
			return;
		}
	}
	delete m;
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