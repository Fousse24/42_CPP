/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:20:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 08:27:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

using std::string;

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
    DiamondTrap(string name);
	DiamondTrap(DiamondTrap const & obj);
    ~DiamondTrap();
	DiamondTrap	&operator = (DiamondTrap const & obj);

	std::string	getName() const;
	void		setName(std::string name);

	using ScavTrap::attack;
	void			whoAmI(void);
};

#endif