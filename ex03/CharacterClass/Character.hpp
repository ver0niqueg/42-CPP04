/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:46:07 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/29 16:51:12 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../AMateriaClass/AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
        
    public:
        Character(std::string const &name);
        Character(const Character &copy);
        Character &operator=(const Character &other);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif