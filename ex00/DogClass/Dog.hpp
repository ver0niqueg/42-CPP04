/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:18:53 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/26 21:31:13 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../AnimalClass/Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &other);
        ~Dog();

        void makeSound() const;
};

#endif