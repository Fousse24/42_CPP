/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:27:49 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/28 13:26:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap() : _name("nameless"), _hp(10), _ep(10), _atk(0)
{
	cout << "(def constructor) Hello World!! I am " << _name << endl;
	
}

ClapTrap::ClapTrap(std::string name) : _hp(10), _ep(10), _atk(0)
{
	cout << "(constructor) Hello World!! This is " << name << endl;
	this->setName(name);
}

ClapTrap::~ClapTrap()
{
	cout << "(destructor) " << this->getName() << ": Oh no! My eye!!" << endl;
}

ClapTrap::ClapTrap( ClapTrap const & obj)
{
	cout << "(copy) More is always better!" << endl;
	*this = obj;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & obj )
{
	cout << "(assignment operator) " << this->getName() << ": Hey! I'm you!" << endl;
	this->setHp(obj.getHp());
	this->setHp(obj.getEp());
	this->setHp(obj.getAtk());

	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	cout << "Claptrap \033[1;33m" << this->getName() << " ";
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	cout << "Claptrap \033[1;33m" << this->getName() << " ";
	if (isDead())
		cout << "is dead. Stop beating a dead bot!\033[0m";
	else
	{
		cout << "takes \033[1;31m" << amount << " damage\033[0m! ";
		cout << "It had \033[1;32m" << this->getHp() << " HP \033[0mand now has \033[1;32m";
		this->setHp(this->getHp() - (int)amount);
		if (this->getHp() < 0)
			this->setHp(0);
		cout << this->getHp() << " HP\033[0m.";
	}
	cout << endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	cout << "Claptrap \033[1;33m" << this->getName() << " ";
	if (isDead())
		cout << "is far too dead to repair itself\033[0m";
	else if (isExhausted())
		cout << "is out of energy to repair itself\033[0m";
	else
	{
		if (getEp() < (int)amount)
			amount = getEp();
		cout << "repairs itself \033[0mfor \033[1;32m" << amount << " HP\033[0m!";
		cout << " It had \033[1;32m" << this->getHp() << " HP \033[0mand now has \033[1;32m";
		this->setHp(this->getHp() + amount);
		cout << this->getHp() << " HP\033[0m.";
		setEp(getEp() - (int)amount);
	}
	cout << endl;
}

bool	ClapTrap::isDead() const
{
	if (getHp() <= 0)
		return (true);
	return (false);
}

bool	ClapTrap::isExhausted() const
{
	if (getEp() <= 0)
		return (true);
	return (false);
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

int ClapTrap::getHp() const
{
	return this->_hp;
}

void ClapTrap::setHp(int hp)
{
	this->_hp = hp;
}

int ClapTrap::getEp() const
{
	return this->_ep;
}

void ClapTrap::setEp(int ep)
{
	this->_ep = ep;
}

int ClapTrap::getAtk() const
{
	return this->_atk;
}

void ClapTrap::setAtk(int atk) 
{
	this->_atk = atk;
}
