/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 17:17:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"

using std::string;
using std::cout;
using std::endl;

int main(void) 
{
	ScavTrap scavy_nameless;
	cout << endl;
	ScavTrap scavy(string("ScavyMcTrappey"));
	cout << endl;
	ScavTrap scaver(scavy);
	cout << endl;
	ClapTrap clappy(string("Clappy"));
	cout << endl;
	
	scavy.attack(clappy.getName());
	clappy.takeDamage(scavy.getAtk());
	cout << endl;

	clappy.attack(scavy.getName());
	scavy.takeDamage(clappy.getAtk());
	scavy.beRepaired(20);
	cout << endl;
	scavy.guardGate();
	cout << endl;
	scavy.takeDamage(150);
	scavy.guardGate();
	cout << endl;


	return 0;
}