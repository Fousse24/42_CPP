/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:10 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 15:02:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using	std::string;
using	std::cout;
using	std::endl;

Cat::Cat()
{
	this->type = "Cat";
	cout << C_COLOR << "it's a cat!" << C_RESET << endl;
}

Cat::Cat( const Cat & src )
{
	type = src.getType();
	cout << C_COLOR << "A cat now has a twin!" << C_RESET << endl;
}

Cat::~Cat()
{
	cout << C_COLOR << "RIP you beautiful cat!" << C_RESET << endl;
}

Cat	&Cat::operator=( Cat const & obj )
{
	this->type = obj.type;
	return *this;
}

void	Cat::makeSound(void) const
{
	cout << C_COLOR << "(non-chalantly) Meoww..." << C_RESET << endl;
}

std::ostream &	operator<<( std::ostream & o, Cat const & i )
{
	o << C_COLOR << "Cat type = " << C_RESET << i.getType();
	return o;
}


