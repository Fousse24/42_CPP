/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:20:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 08:27:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::string;

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
    FragTrap(string name);
	FragTrap(FragTrap const & obj);
    ~FragTrap();
	FragTrap	&operator = (FragTrap const & obj);

	void	attack(const string & target);
	void	highFivesGuys();
};

#endif