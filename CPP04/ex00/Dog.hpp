/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:53 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 16:00:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

#define	D_COLOR	"\033[1;34m"
#define	D_RESET	"\033[m"

using	std::string;

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();

		Dog	&operator=(Dog const & obj);

		virtual void	makeSound(void) const;

};

std::ostream	&operator<<( std::ostream & o, Dog const & i );

#endif