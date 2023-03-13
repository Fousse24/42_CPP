/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:10 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 15:50:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

using	std::string;
using	std::cout;
using	std::endl;

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	cout << "An abomination has been born!" << endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) : type(src.getType())
{
	cout << "An abomination now has a twin!" << endl;
}

WrongAnimal::~WrongAnimal()
{
	cout << "An abomination just died..." << endl;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const & obj )
{
	this->type = obj.type;
	return *this;
}

void	WrongAnimal::makeSound(void) const
{
	cout << "(͈̦̰̗͓͍ͣͭ̌ͪ̇͒͒ͅS͉͇̯͓͙̦͚͐C̪̝̯͍̪̯̣ͤ̾ͯ͋̐ͨ̃R͓̤̜͌́́Ẻ͙̺̦̜̖̜̇̃E̞̒̿̓ͅC͔̀ͦ̌̚Ḥ̮̙̍́I̱͋͑̊ͩNǴ͙̜̖͉̺͛̿͗͆ ͙͙͇̣̲͕͑ͣ̊̈́̄Š̓̚O͇̘̻͖̱̫̝ͫU͇͔ͨ̓̊N̓̐ͫ̈Ḓ͖͉̖̄̃ͤ͂̇)̍ͩ̿" << endl;
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

string	WrongAnimal::getType() const
{
	return this->type;
}

std::ostream &	operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << "WrongAnimal type = " << i.getType();
	return o;
}


