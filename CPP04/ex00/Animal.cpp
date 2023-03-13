/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:10 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 15:50:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using	std::string;
using	std::cout;
using	std::endl;

Animal::Animal() : type("Animal")
{
	cout << "An animal has been born!" << endl;
}

Animal::Animal( const Animal & src ) : type(src.getType())
{
	cout << "An animal now has a twin!" << endl;
}

Animal::~Animal()
{
	cout << "An animal just died..." << endl;
}

Animal	&Animal::operator=( Animal const & obj )
{
	this->type = obj.type;
	return *this;
}

void	Animal::makeSound(void) const
{
	cout << "You hear some unknown animal sound. I mean, what the hell is this?" << endl;
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

string	Animal::getType() const
{
	return this->type;
}

std::ostream &	operator<<( std::ostream & o, Animal const & i )
{
	o << "Animal type = " << i.getType();
	return o;
}


