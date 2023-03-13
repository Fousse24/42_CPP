/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:50:36 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 11:07:32 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"
#include	<iostream>

Zombie::Zombie()
{
}

Zombie::Zombie( std::string name )
{
	this->setName(name);
}

Zombie::~Zombie()
{
	std::cout << "\033[1;31m" << this->name << " has deteriorated beyond undead capacities";
	std::cout << "\033[0m" << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}