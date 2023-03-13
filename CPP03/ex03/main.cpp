/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 17:32:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"ClapTrap.hpp"
#include	"FragTrap.hpp"
#include	"ScavTrap.hpp"
#include	"DiamondTrap.hpp"

using std::string;
using std::cout;
using std::endl;

int main(void) 
{
	ClapTrap claper(string("Claper"));
	cout << endl;
	FragTrap frager(string("Frager"));
	cout << endl;
	ScavTrap scaver(string("Scaver"));
	cout << endl;
	DiamondTrap	diamer(string("Diamer"));
	cout << endl;

	cout << endl;
	cout << "Diamer atk : " << diamer.getAtk() << endl;
	cout << "Diamer hp  : " << diamer.getHp() << endl;
	cout << "Diamer ep  : " << diamer.getEp() << endl;
	cout << endl;

	cout << endl;
	claper.attack(frager.getName());
	frager.attack(scaver.getName());
	scaver.attack(diamer.getName());
	diamer.takeDamage(scaver.getAtk());
	diamer.attack(diamer.getName());
	diamer.takeDamage(diamer.getAtk());
	diamer.beRepaired(diamer.getEp() - 5);
	cout << endl;
	diamer.whoAmI();
	diamer.guardGate();
	diamer.highFivesGuys();
	cout << endl;
	
	diamer.takeDamage(1000);
	diamer.takeDamage(1000);
	cout << endl;

	return 0;
}