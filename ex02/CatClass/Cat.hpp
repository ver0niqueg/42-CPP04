/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:32:25 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 17:11:24 by vgalmich         ###   ########.fr       */
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
		~Cat();

		void makeSound() const;
		Brain *getBrain( void ) const;
};

#endif