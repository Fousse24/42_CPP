/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:56:19 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 16:53:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
using std::string;
using std::cout;
using std::endl;

// Constructors
Cure::Cure() : AMateria(string("cure"))
{
	cout << "\033[1;32m";
	cout << "An *cure* materia has been constructed (default)";
	cout << "\033[0m" << endl;
}

Cure::Cure(Cure const & obj) : AMateria(string(obj.getType()))
{
	cout << "\033[1;32m";
	cout << "An *cure* materia has been constructed";
	cout << "\033[0m" << endl;
	_type = obj.getType();
}

// Destructor
Cure::~Cure()
{
	cout << "\033[1;32m";
	cout << "An *cure* materia has been destroyed";
	cout << "\033[0m" << endl;
}

// Assignment
Cure	&Cure::operator=( Cure const & )
{
	return *this;
}

// Functions
Cure	*Cure::clone() const
{
	Cure	*cure = new Cure();
	cout << "\033[1;32m";
	cout << "An *cure* materia has been cloned.";
	cout << "\033[0m" << endl;
	return cure;
}

void	Cure::use(ICharacter & target)
{
	cout << "\033[1;32m";
	cout << "* heals " << target.getName() << "\'s wounds *";
	cout << "\033[0m" << endl;
}

