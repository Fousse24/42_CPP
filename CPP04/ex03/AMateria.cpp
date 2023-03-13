/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:26:41 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/09 15:52:49 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
using std::string;

// Constructors
AMateria::AMateria()
{
	_type = "";
}

AMateria::AMateria(string const & type)
{
	_type = type;
}

AMateria::AMateria(AMateria const & obj)
{
	_type = obj.getType();
}

// Destructor
AMateria::~AMateria() 
{
}

void	AMateria::use(ICharacter &)
{

}

// Assignment
AMateria	&AMateria::operator=( AMateria const & obj )
{
	_type = obj.getType();
	return *this;
}

// Functions

string const &	AMateria::getType() const
{
	return _type;
}
