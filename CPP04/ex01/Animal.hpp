/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:53 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/04 16:40:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

using	std::string;

class Animal
{
	protected:
		string type;

	public:
		Animal();
		Animal(Animal const & src);
		virtual ~Animal();

		Animal	&operator=(Animal const & obj);

		void	setType(string type);
		string	getType(void) const;

		virtual void	makeSound(void) const;

};

std::ostream	&operator<<( std::ostream & o, Animal const & i );

#endif