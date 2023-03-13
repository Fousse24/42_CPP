/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:27:49 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/28 13:26:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

using std::cout;
using std::endl;

DiamondTrap::DiamondTrap() : ClapTrap()
{
	cout << "(def constructor diamond) and I'm also a nameless DiamondTrap" << endl;
	ClapTrap::_name = "nameless_claptrap";
	this->setName("nameless");
	_atk = (FragTrap::_atk);
	_ep = (ScavTrap::_ep);
	_hp = (FragTrap::_hp);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	cout << "(constructor diamond) and I'm also a DiamondTrap named " << name << endl;
	//ClapTrap::_name = name + "_clap_name";
	this->setName(name);

	// ClapTrap::_atk = FragTrap::_atk;
	_atk = (FragTrap::_atk);
	_ep = (ScavTrap::_ep);
	_hp = (FragTrap::_hp);
}

DiamondTrap::~DiamondTrap()
{
	cout << "(destructor diamond) " << this->getName() << ": my diamond is shattering..." << endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & obj) : ClapTrap(obj.getName() + "_claptrap"), ScavTrap(obj.getName()), FragTrap(obj.getName())
{
	cout << "(copy diamond) " << this->getName() << ": More " << obj.getName() << " is always better!" << endl;
	*this = obj;
}

std::string DiamondTrap::getName() const
{
	return this->_name;
}

void DiamondTrap::setName(std::string name)
{
	this->_name = name;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & obj )
{
	cout << "(assignment operator diamond) " << this->getName() << ": Hey! I'm becoming " << obj.getName() << endl;
	this->setName(obj.getName());
	this->setHp(obj.getHp());
	this->setEp(obj.getEp());
	this->setAtk(obj.getAtk());

	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	cout << "I'm " << this->getName() << " and my Claptrap name is " << ClapTrap::getName() << endl;
}
