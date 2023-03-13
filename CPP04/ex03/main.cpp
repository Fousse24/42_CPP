/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:19:40 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 17:20:18 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

using std::cout;
using std::string;
using std::endl;

int	main(void)
{
	cout << "MATERIA SOURCE CREATION" << endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	cout << "--------------------" << endl << endl;

	cout << "CLOUD AND RED CHARACTER CREATION" << endl;
	ICharacter* cloud = new Character("Cloud");
	ICharacter* red = new Character("Red XIII");
	cout << "--------------------" << endl << endl;

	cout << "EQUIP/UNEQUIP MATERIA ON CHARACTER" << endl;
	AMateria* tmp;
	AMateria* tmp_unequip;
	tmp = src->createMateria("cure");
	red->equip(tmp);
	tmp = src->createMateria("ice");
	cloud->equip(tmp);
	tmp = src->createMateria("bleh");
	tmp_unequip = src->createMateria("cure");
	cloud->equip(tmp_unequip);
	tmp = src->createMateria("ice");
	cloud->equip(tmp);
	tmp = src->createMateria("cure");
	cloud->equip(tmp);
	tmp = src->createMateria("ice");
	cloud->equip(tmp);
	delete tmp;
	cloud->unequip(1);
	delete tmp_unequip;
	tmp = src->createMateria("cure");
	cloud->equip(tmp);
	cout << "--------------------" << endl << endl;

	cout << "MATERIA USAGE" << endl;
	ICharacter* bob = new Character("bob");
	cloud->use(0, *bob);
	cloud->use(1, *bob);
	cloud->use(2, *bob);
	cloud->use(3, *bob);
	cloud->use(4, *bob);
	cout << "--------------------" << endl << endl;

	cout << "CHARACTER DELETION" << endl;
	delete bob;
	delete cloud;
	delete red;
	cout << "--------------------" << endl << endl;

	cout << "COPY AND ASSIGNMENT TESTING" << endl;
	Character* barret = new Character("Barret");
	barret->equip(src->createMateria("ice"));
	barret->equip(src->createMateria("cure"));
	Character* barret_clone = new Character(*barret);
	Character barret_clone2;
	barret_clone2 = *barret_clone;
	delete barret_clone;
	delete barret;
	cout << "--------------------" << endl << endl;
	
	cout << "SOURCE DESTRUCTION" << endl;
	delete src;
	cout << endl;
	return 0;
}