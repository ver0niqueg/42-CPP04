/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:55:02 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 15:34:39 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define CYAN "\033[36m"
#define RST "\033[0m"

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void    makeSound() const;
		std::string     getType() const;
};

#endif