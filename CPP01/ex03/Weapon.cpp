/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:50:36 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 15:12:10 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Weapon.hpp"
#include	<iostream>

Weapon::Weapon()
{

}

Weapon::Weapon( std::string type )
{
	this->setType(type);
}

Weapon::~Weapon()
{
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}

const std::string	&Weapon::getType( void )
{
	return (this->type);
}