/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:20:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 08:27:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

using std::string;

class ClapTrap
{
protected:
	string	_name;
	int		_hp;
	int		_ep;
	int		_atk;


public:
	ClapTrap();
    ClapTrap(string name);
	ClapTrap(ClapTrap const & obj);
    ~ClapTrap();
	ClapTrap	&operator = (ClapTrap const & obj);

	void	attack(const string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	isDead(void) const;
	bool	isExhausted(void) const;

	string	getName(void) const;
	void	setName(string name);

	int		getHp(void) const;
	void	setHp(int hp);

	int		getEp(void) const;
	void	setEp(int ep);

	int		getAtk(void) const;
	void	setAtk(int atk);
};

#endif