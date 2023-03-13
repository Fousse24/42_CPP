/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:35 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 17:19:59 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
#define HumanB_HPP

#include	<string>
#include	"Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon		*weapon;

public:
	HumanB(std::string name);
    ~HumanB();

	void				setName(std::string name);
	void				setWeapon(Weapon &weapon);
	std::string			getName(void);
	Weapon				&getWeapon(void);

	void	attack( void );
};

#endif