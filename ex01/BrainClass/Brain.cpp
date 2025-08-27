/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:37:46 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/27 18:06:45 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = "Empty idea";
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &copy)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = copy.ideas[i];
    std::cout << "Brain copy constructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain assignment operator called." << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
    static std::string empty = ""; // valeur de retour si index hors limites
    if (index < 0 || index >= 100) 
    {
        std::cout << "Brain: index is out of range" << std::endl;
        return empty;
    }
    return ideas[index];
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "Brain: index is out of range, impossible to set an idea" << std::endl;
        return ;
    }
    ideas[index] = idea;
}
