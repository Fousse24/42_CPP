/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:53 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 17:38:59 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

using	std::string;

class WrongAnimal
{
	protected:
		string type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		virtual ~WrongAnimal();

		WrongAnimal	&operator=(WrongAnimal const & obj);

		void	setType(string type);
		string	getType(void) const;

		void	makeSound(void) const;

};

std::ostream	&operator<<( std::ostream & o, WrongAnimal const & i );

#endif