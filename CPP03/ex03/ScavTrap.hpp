/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:20:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 08:27:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::string;

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
    ScavTrap(string name);
	ScavTrap(ScavTrap const & obj);
    ~ScavTrap();
	ScavTrap	&operator = (ScavTrap const & obj);

	void	attack(const string & target);
	void	guardGate();
};

#endif