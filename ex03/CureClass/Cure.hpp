/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:06:31 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/29 15:04:50 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "../AMateriaClass/AMateria.hpp"
#include "../CharacterClass/ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &copy);
        Cure &operator=(const Cure &other);
        ~Cure();

        virtual AMateria* clone() const ;
        virtual void use(ICharacter &target);
};

#endif