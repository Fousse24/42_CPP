/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:50:36 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 13:30:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"HumanB.hpp"
#include	<iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::setName(std::string name)
{
	this->name = name;
}

std::string	HumanB::getName(void)
{
	return (this->name);
}

Weapon	&HumanB::getWeapon(void)
{
	return (*this->weapon);
}

void	HumanB::attack(void)
{
	std::cout << "\033[0;33m" << this->getName() << "\033[0m";
	std::cout << " attacks with his ";
	if (!weapon)
		std::cout << "\033[0;31m" << "weak weaponless hands" << "\033[0m";
	else
		std::cout << "\033[0;31m" << this->getWeapon().getType() << "\033[0m";
	std::cout << std::endl;
}