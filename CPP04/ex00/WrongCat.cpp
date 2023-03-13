/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:10 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 15:02:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

using	std::string;
using	std::cout;
using	std::endl;

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	cout << W_COLOR << "it's a cat(?)!" << W_RESET << endl;
}

WrongCat::WrongCat( const WrongCat & src )
{
	type = src.getType();
	cout << W_COLOR << "A very ugly cat now has a twin!" << W_RESET << endl;
}

WrongCat::~WrongCat()
{
	cout << W_COLOR << "RIP you disgusting cat!" << W_RESET << endl;
}

WrongCat	&WrongCat::operator=( WrongCat const & obj )
{
	this->type = obj.type;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	cout << W_COLOR << "(disgustingly) Me-ouchhh..." << W_RESET << endl;
}

std::ostream &	operator<<( std::ostream & o, WrongCat const & i )
{
	o << W_COLOR << "WrongCat type = " << W_RESET << i.getType();
	return o;
}


