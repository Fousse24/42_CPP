/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:35 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 13:40:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include	<string>

class Zombie
{
private:
	std::string name;

public:
    Zombie();
	Zombie( std::string name );
    ~Zombie();

	void	setName( std::string name );
	void	announce( void );

};

#endif