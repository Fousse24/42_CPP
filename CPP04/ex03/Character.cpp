/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:55:15 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 17:20:04 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
using std::string;
using std::cout;
using std::endl;

Character::Character()
{
	_name = "";
	for (int i = 0; i < MATERIA_N_SLOT; i++)
		_materias[i] = NULL;
}

Character::Character(string const & name)
{
	_name = name;
	cout << "\033[1;31m";
	cout << getName() << " is becoming a living character";
	cout << "\033[0m" << endl;
	for (int i = 0; i < MATERIA_N_SLOT; i++)
		_materias[i] = NULL;
}

Character::Character(Character const & src)
{
	for (int i = 0; i < MATERIA_N_SLOT; i++)
		_materias[i] = NULL;
	*this = src;
}

Character::~Character()
{
	cout << "\033[1;31m";
	cout << getName() << " is dying";
	cout << "\033[0m" << endl;
	for (int i = 0; i < MATERIA_N_SLOT; i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
	}
}

Character & Character::operator=(Character const & obj)
{
	AMateria const	*m;

	_name = obj.getName();
	cout << "\033[1;31m";
	cout << getName() << " is being copied";
	cout << "\033[0m" << endl;
	for (int i = 0; i < MATERIA_N_SLOT; i++)
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

string const & Character::getName() const
{
	return _name;
}

AMateria const * Character::getMateria(int idx) const
{
	if (idx < MATERIA_N_SLOT)
		return _materias[idx];
	else
		return NULL;
}

void Character::setMateria(int idx, AMateria * m)
{
	if (idx < MATERIA_N_SLOT)
	{
		this->_materias[idx] = m;
	}
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	cout << "\033[1;31m";
	for (int i = 0; i < MATERIA_N_SLOT; i++)
	{
		if (this->getMateria(i) == NULL)
		{
			cout << getName() << " has equipped *" << m->getType();
			cout << "* materia in slot " << i << "!\033[0m" << endl;
			this->setMateria(i, m);
			return;
		}
	}
	cout << getName() << " has no space to equip *" << m->getType();
	cout << "* materia.\033[0m" << endl;
}

void Character::unequip(int idx)
{
	cout << "\033[1;31m";
	if (this->getMateria(idx) != NULL)
	{
		cout << getName() << " has unequipped the *" << this->getMateria(idx)->getType();
		cout << "* materia in slot " << idx << ".";
		this->setMateria(idx, NULL);
	}
	else
	{
		cout << getName() << " has no materia equipped in slot " << idx;
		cout << ".";
	}
	cout << "\033[0m" << endl;
}

void Character::use(int idx, ICharacter & target)
{
	cout << "\033[1;31m";
	if (idx < MATERIA_N_SLOT && _materias[idx] != NULL)
	{
		cout << this->getName() << " ";
		_materias[idx]->use(target);
	}
	cout << "\033[0m";
}
