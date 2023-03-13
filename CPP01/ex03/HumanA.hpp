/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:35 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 17:22:50 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
#define HumanA_HPP

#include	<string>
#include	"Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon		*weapon;

public:
	HumanA(std::string name, Weapon &weapon);
    ~HumanA();

	void				setName(std::string name);
	void				setWeapon(Weapon &weapon);
	std::string			getName(void);
	Weapon				&getWeapon(void);

	void	attack( void );
};

#endif