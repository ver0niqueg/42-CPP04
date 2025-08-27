/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:18:53 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/27 17:28:32 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../AnimalClass/Animal.hpp"
#include "../BrainClass/Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;
		
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		virtual ~Dog(); // virtual added

		virtual void makeSound() const; // virtual added
		void setIdea(int index, const std::string &idea);
        const std::string &getIdea(int index) const;
};

#endif