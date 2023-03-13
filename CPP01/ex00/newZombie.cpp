/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:42:38 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 12:16:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

Zombie*	newZombie( std::string name )
{
	Zombie*	zombie;

	zombie = new Zombie(name);
	if (zombie)
		zombie->announce();
	return (zombie);
}