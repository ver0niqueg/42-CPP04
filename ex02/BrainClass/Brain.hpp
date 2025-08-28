/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:06:57 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/28 13:58:17 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINCLASS_HPP
#define BRAINCLASS_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		Brain& operator=(const Brain &other);
		~Brain();

		const std::string &getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
};

#endif

/*
✨ Détails importants
- Attribut Brain* brain
- Alloué dans le constructeur (new Brain())
- Libéré dans le destructeur (delete brain)
- Constructeur de copie et opérateur=
- Deep copy : alloue un nouveau Brain et copie toutes les idées de l’autre objet.
- Méthodes setIdea / getIdea
Pour accéder aux idées depuis Cat ou Dog.
- Polymorphisme
makeSound() est virtual → fonctionne via Animal*.
*/