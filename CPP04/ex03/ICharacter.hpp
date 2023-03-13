/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/09 15:33:39 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;
using std::string;

class ICharacter
{
public:
	virtual ~ICharacter() {}
	
	virtual string const & getName() const = 0;

	virtual void equip(AMateria * m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter & target) = 0;
};

#endif