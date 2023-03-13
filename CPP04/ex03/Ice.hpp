/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/09 15:35:00 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

using std::string;

class Ice : public AMateria
{
protected:
	string	_type;

public:
	Ice();
	Ice(Ice const & obj);
	~Ice();

	Ice	&operator=(Ice const & obj);

	Ice	*clone() const;
	void use(ICharacter & target);
};

#endif