/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 13:28:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Weapon.hpp"
#include	"HumanA.hpp"
#include	"HumanB.hpp"

int main(void)
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	bob.getWeapon().setType("morning star");
	club.setType("some other type of club");
	bob.attack();

	club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

	return 0;
}