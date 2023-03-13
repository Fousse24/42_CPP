/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:53 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 16:00:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

#define	W_COLOR	"\033[1;33m"
#define	W_RESET	"\033[m"

using	std::string;

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat	&operator=(WrongCat const & obj);

		void	makeSound(void) const;

};

std::ostream	&operator<<( std::ostream & o, WrongCat const & i );

#endif