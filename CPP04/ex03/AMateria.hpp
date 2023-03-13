/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/09 15:42:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
class ICharacter;
using std::string;

class AMateria
{
protected:
	string	_type;
public:
	AMateria();
	AMateria(string const & type);
	AMateria(AMateria const & obj);
	virtual	~AMateria();
	
	AMateria	&operator=(AMateria const & obj);
	
	string const & getType() const; //Returns the materia type
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif