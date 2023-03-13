/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:55:15 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 17:21:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
using std::string;
using std::cout;
using std::endl;

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MATERIASOURCE_N_SLOT; i++)
		_materias[i] = NULL;
	cout << "\033[1;34m";
	cout << "The Materia Source has been created";
	cout << "*\033[0m" << endl;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	cout << "\033[1;34m";
	cout << "The Materia Source is fading away";
	cout << "\033[0m" << endl;
	for (int i = 0; i < MATERIASOURCE_N_SLOT; i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & obj)
{
	AMateria const	*m;

	for (int i = 0; i < MATERIASOURCE_N_SLOT; i++)
	{
		m = obj.getMateria(i);
		if (_materias[i] != NULL)
		{
			delete _materias[i];
			_materias[i] = NULL;
		}
		if (m != NULL)
			this->setMateria(i, m->clone());
	}
	return *this;
}

AMateria const * MateriaSource::getMateria(int idx) const
{
	if (idx < MATERIASOURCE_N_SLOT)
		return (AMateria const *)_materias[idx];
	else
		return NULL;
}

void MateriaSource::setMateria(int idx, AMateria * m)
{
	if (idx < MATERIASOURCE_N_SLOT)
	{
		this->_materias[idx] = m;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	cout << "\033[1;34m";
	for (int i = 0; i < MATERIASOURCE_N_SLOT; i++)
	{
		if (this->getMateria(i) == NULL)
		{
			cout << "The Materia Source has learned *" << m->getType();
			cout << "*\033[0m!" << endl;
			this->setMateria(i, m);
			return;
		}
	}
	cout << "The Materia Source has no space to learn *" << m->getType();
	cout << "*\033[0m" << endl;
	delete m;
}

AMateria* MateriaSource::createMateria(string const & type)
{
	cout << "\033[1;34m";
	AMateria const	*m;
	for (int i = 0; i < MATERIASOURCE_N_SLOT; i++)
	{
		m = this->getMateria(i);
		if (m != NULL && m->getType() == type)
		{
			cout << "Materia Source has created a *" << type << "* materia!\033[0m" << endl;
			return (m->clone());
		}
	}
	cout << "The Materia Source can't create materia of type *";
	cout << type << "*\033[0m" << endl;
	return 0;
}

