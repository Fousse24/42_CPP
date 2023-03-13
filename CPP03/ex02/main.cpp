/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 17:25:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"ClapTrap.hpp"
#include	"FragTrap.hpp"

using std::string;
using std::cout;
using std::endl;

int main(void) 
{
	FragTrap fragy(string("fragyMcTrappey"));
	cout << endl;
	FragTrap frager(string("frager"));
	cout << endl;
	ClapTrap clappy(string("Clappy"));

	cout << endl;
	fragy.attack(clappy.getName());
	clappy.takeDamage(fragy.getAtk());
	cout << endl;

	fragy.highFivesGuys();
	cout << endl;

	clappy.attack(fragy.getName());
	fragy.takeDamage(clappy.getAtk());
	fragy.beRepaired(fragy.getEp());
	cout << endl;

	fragy.highFivesGuys();
	cout << endl;

	return 0;
}