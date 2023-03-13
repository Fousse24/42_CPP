/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/09 15:34:51 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

using std::string;

class Cure : public AMateria
{
protected:
	string	_type;

public:
	Cure();
	Cure(Cure const & obj);
	~Cure();

	Cure	&operator=(Cure const & obj);

	Cure	*clone() const;
	void	use(ICharacter & target);
};

#endif