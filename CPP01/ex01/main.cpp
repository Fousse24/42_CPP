/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 13:49:21 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main( void )
{
	int		i;
	Zombie	*zombies;
	Zombie	*zombies2;

	zombies = zombieHorde(7, "Bob");
	for (i = 0; i < 7; i++)
		zombies[i].announce();
	delete [] zombies;

	zombies = zombieHorde(3, "Jacob");
	for (i = 0; i < 3; i++)
		zombies[i].announce();

	zombies2 = zombieHorde(2, "Bruno");
	for (i = 0; i < 2; i++)
		zombies2[i].announce();
	delete [] zombies;
	delete [] zombies2;
	return (0);
}