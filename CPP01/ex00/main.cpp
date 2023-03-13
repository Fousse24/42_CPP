/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 11:16:45 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string>
#include	<iostream>
#include	"Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int	main( void )
{
	Zombie	*zombie1_heap;
	Zombie	*zombie2_heap;

	zombie1_heap = newZombie("Tokutaro");
	randomChump("Collet");
	zombie2_heap = newZombie("Justine");
	randomChump("Laube");
	delete zombie1_heap;
	delete zombie2_heap;
	return (0);
}