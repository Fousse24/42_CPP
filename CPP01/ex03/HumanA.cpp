/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:50:36 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 17:22:49 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"HumanA.hpp"
#include	<iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA()
{
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}

std::string	HumanA::getName( void )
{
	return (this->name);
}

Weapon	&HumanA::getWeapon( void )
{
	return (*this->weapon);
}

void	HumanA::attack(void)
{
	std::cout << "\033[0;33m" << this->getName() << "\033[0m";
	std::cout << " attacks with his ";
	std::cout << "\033[0;31m" << this->getWeapon().getType() << "\033[0m";
	std::cout << std::endl;
}