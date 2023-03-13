/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:10:46 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 17:25:03 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using std::cout;
using std::endl;

FragTrap::FragTrap()
{
	cout << "(def constructor frag) Hello World!! I am " << name << endl;
	this->setAtk(30);
	this->setEp(100);
	this->setHp(100);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	cout << "(constructor frag) and I'm also a FragTrap named " << name << endl;
	this->setName(name);
	this->setAtk(30);
	this->setEp(100);
	this->setHp(100);
}

FragTrap::~FragTrap()
{
	cout << "(destructor frag) " << this->getName() << ": Oh no! I'm out of ideas!!" << endl;
}

FragTrap::FragTrap( FragTrap const & obj) : ClapTrap(obj.getName())
{
	cout << "(copy frag) " << this->getName() << ": More " << obj.getName() << " is always better!" << endl;
	*this = obj;
}

FragTrap &	FragTrap::operator=( FragTrap const & obj )
{
	cout << "(assignment operator frag) " << this->getName() << ": Hey! I'm becoming " << obj.getName() << endl;
	this->setName(obj.getName());
	this->setHp(obj.getHp());
	this->setHp(obj.getEp());
	this->setHp(obj.getAtk());

	return *this;
}

void	FragTrap::attack(const std::string & target)
{
	cout << "FragTrap \033[1;35m" << this->getName() << " ";
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

void	FragTrap::highFivesGuys(void)
{
	cout << "FragTrap " << this->getName();
	if (isDead())
		cout << " is far too dead to high fives everybody\033[0m";
	else if (isExhausted())
		cout << " is out of energy to raise his weak robotic arm\033[0m";
	else
		cout << ": let's high five like the best amigos!!";
	cout << endl;
}
