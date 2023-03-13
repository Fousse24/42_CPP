/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:56:19 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 16:53:26 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
using std::string;
using std::cout;
using std::endl;

// Constructors
Ice::Ice() : AMateria(string("ice"))
{
	cout << "An *ice* materia has been constructed (default)" << endl;
}

Ice::Ice(Ice const & obj) : AMateria(obj.getType())
{
	cout << "An *ice* materia has been constructed" << endl;
	_type = obj.getType();
}

// Destructor
Ice::~Ice()
{
	cout << "An *ice* materia has been destroyed" << endl;
}

// Assignment
Ice	&Ice::operator=( Ice const & )
{
	return *this;
}

// Functions
Ice	*Ice::clone() const
{
	Ice	*ice = new Ice();
	cout << "An *ice* materia has been cloned." << endl;
	return ice;
}

void	Ice::use(ICharacter & target)
{
	cout << "\033[1;39m";
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
	cout << "\033[0m";
}

