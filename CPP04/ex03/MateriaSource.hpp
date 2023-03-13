/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 17:12:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# define MATERIASOURCE_N_SLOT 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_materias[MATERIASOURCE_N_SLOT];

public:
	MateriaSource();
	MateriaSource( MateriaSource const & src );
	~MateriaSource();

	MateriaSource &	operator=( MateriaSource const & obj );

	AMateria const *	getMateria(int idx) const;
	void 				setMateria(int idx, AMateria * m);

	void 		learnMateria( AMateria* m);
	AMateria*	createMateria( std::string const & type );
};

#endif