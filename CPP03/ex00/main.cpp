/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 17:02:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"ClapTrap.hpp"

using std::string;

int main(void) 
{
	ClapTrap clappy(string("Clappy"));
	ClapTrap clapper(string("Clapper"));
	std::cout << std::endl;

	clappy.attack(clapper.getName());
	clapper.takeDamage(clappy.getAtk());
	std::cout << std::endl;

	clapper.attack(clappy.getName());
	clappy.takeDamage(clapper.getAtk());
	std::cout << std::endl;

	clapper.beRepaired(11111);
	std::cout << std::endl;
	
	clappy.setAtk(9999);
	clappy.attack(clapper.getName());
	clapper.takeDamage(clappy.getAtk());
	clapper.attack(clappy.getName());
	clapper.beRepaired(100);
	clappy.beRepaired(50);
	clappy.beRepaired(10);
	clappy.attack("whatever");
	std::cout << std::endl;

	return 0;
}