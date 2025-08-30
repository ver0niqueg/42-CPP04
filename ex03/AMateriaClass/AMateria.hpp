/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:12:19 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 18:05:20 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#define CYAN "\033[36m"
#define RST "\033[0m"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		
		std::string const &getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif