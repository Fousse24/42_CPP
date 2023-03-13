/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:10 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 15:02:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using	std::string;
using	std::cout;
using	std::endl;

Dog::Dog() : brain(new Brain())
{
	this->type = "Dog";
	cout << D_COLOR << "it's a dog!" << D_RESET << endl;
}

Dog::Dog( const Dog & obj ) : brain(new Brain(*obj.brain))
{
	type = obj.getType();
	cout << D_COLOR << "A dog now has a twin!" << D_RESET << endl;
}

Dog::~Dog()
{
	cout << D_COLOR << "RIP furry friend... You were the best boi." << D_RESET << endl;
	delete brain;
}

Dog	&Dog::operator=( Dog const & obj )
{
	if (&obj != this)
	{
		this->type = obj.type;
		delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	cout << D_COLOR << "(Excitingly) WOOF WOOF!!!!" << D_RESET << endl;
}

std::ostream &	operator<<( std::ostream & o, Dog const & i )
{
	o << D_COLOR << "Dog type = " << D_RESET << i.getType();
	return o;
}


