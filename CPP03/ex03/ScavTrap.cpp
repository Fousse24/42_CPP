/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:27:49 by sfournie          #+#    #+#             */
/*   Updated: 2022/06/21 13:51:11 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

ScavTrap::ScavTrap()
{
	cout << "(def constructor scav) Hello World!! I am " << _name << endl;
	this->setAtk(20);
	this->setEp(50);
	this->setHp(100);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	cout << "(constructor scav) and I'm also a ScavTrap named " << name << endl;
	this->setAtk(20);
	this->setEp(50);
	this->setHp(100);
}

ScavTrap::~ScavTrap()
{
	cout << "(destructor scav) " << this->getName() << ": Oh no! My other eye!!" << endl;
}

ScavTrap::ScavTrap( ScavTrap const & obj) : ClapTrap(obj.getName())
{
	cout << "(copy scav) " << this->getName() << ": More " << obj.getName() << " is always better!" << endl;
	*this = obj;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & obj )
{
	cout << "(assignment operator scav) " << this->getName() << ": Hey! I'm becoming " << obj.getName() << endl;
	this->setName(obj.getName());
	this->setHp(obj.getHp());
	this->setEp(obj.getEp());
	this->setAtk(obj.getAtk());

	return *this;
}

void	ScavTrap::attack(const std::string & target)
{
	cout << "ScavTrap \033[1;34m" << this->getName() << " ";
	if (isDead())
		cout << "is far too dead to attack\033[0m";
	else if (isExhausted())
		cout << "is too tired to attack\033[0m";
	else
	{
		cout << "attacks " << target << "\033[0m, ";
		cout << "causing \033[1;31m" << this->getAtk() << " damage\033[0m!";
	}
	cout << endl;
}

void	ScavTrap::guardGate(void)
{
	cout << "ScavTrap " << this->getName();
	if (isDead())
		cout << " is far too dead to guard itself";
	else if (isExhausted())
		cout << " is out of energy to guard itself";
	else
	{
		cout << ": I am now in uber-duper Gate Keepa mode!";
	}
	cout << endl;
}
