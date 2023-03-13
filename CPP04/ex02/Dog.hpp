/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:53 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/04 15:59:46 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

#define	D_COLOR	"\033[1;34m"
#define	D_RESET	"\033[m"

using	std::string;

class Dog : public AAnimal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(Dog const & obj);
		~Dog();

		Dog	&operator=(Dog const & obj);

		virtual void	makeSound(void) const;

};

std::ostream	&operator<<( std::ostream & o, Dog const & i );

#endif
