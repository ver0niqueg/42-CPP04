/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:20:23 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/28 18:39:12 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "../CharacterClass/ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &copy);
        Ice &operator=(const Ice &other);
        ~Ice();

        virtual AMateria* clone() const ;
        virtual void use(ICharacter &target);
};

#endif