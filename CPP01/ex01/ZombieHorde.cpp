/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:42:38 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 13:39:35 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

Zombie*	zombieHorde( int N, std::string name )
{
	int		i;
	Zombie*	zombie;

	zombie = new Zombie[N]; 
	if (!zombie)
		return (NULL);
	for (i = 0; i < N; i++)
	{
		zombie[i].setName(name);
	}
	return (zombie);
}