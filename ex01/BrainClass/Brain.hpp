/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:06:57 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/30 15:10:55 by vgalmich         ###   ########.fr       */
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