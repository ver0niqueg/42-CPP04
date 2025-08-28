/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:32:25 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/28 15:05:29 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "../AAnimalClass/AAnimal.hpp"
#include "../BrainClass/Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* brain;
		
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &other);
		virtual ~Cat(); // virtual added

		virtual void makeSound() const; // virtual added
		void setIdea(int index, const std::string &idea);
        const std::string &getIdea(int index) const;
};

#endif