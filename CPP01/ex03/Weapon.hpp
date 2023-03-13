/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:35 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 15:12:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include	<string>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	Weapon(std::string name);
    ~Weapon();

	void				setType(std::string type);
	const std::string	&getType(void);
};

#endif