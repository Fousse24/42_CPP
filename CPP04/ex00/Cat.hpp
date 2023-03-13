/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:53 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 16:00:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

#define	C_COLOR	"\033[1;31m"
#define	C_RESET	"\033[m"

using	std::string;

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();

		Cat	&operator=(Cat const & obj);

		virtual void	makeSound(void) const;

};

std::ostream	&operator<<( std::ostream & o, Cat const & i );

#endif