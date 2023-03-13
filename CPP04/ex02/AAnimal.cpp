/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:10 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 15:50:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

using	std::string;
using	std::cout;
using	std::endl;

AAnimal::AAnimal() : type("AAnimal")
{
	cout << "An animal has been born!" << endl;
}

AAnimal::AAnimal( const AAnimal & src ) : type(src.getType())
{
	cout << "An animal now has a twin!" << endl;
}

AAnimal::~AAnimal()
{
	cout << "An animal just died..." << endl;
}

AAnimal	&AAnimal::operator=( AAnimal const & obj )
{
	this->type = obj.type;
	return *this;
}

void	AAnimal::makeSound(void) const
{
	cout << "You hear some unknown animal sound. I mean, what the hell is this?" << endl;
}

void	AAnimal::setType(std::string type)
{
	this->type = type;
}

string	AAnimal::getType() const
{
	return this->type;
}

std::ostream &	operator<<( std::ostream & o, AAnimal const & i )
{
	o << "AAnimal type = " << i.getType();
	return o;
}


