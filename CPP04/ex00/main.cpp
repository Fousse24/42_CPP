/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:19:40 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 16:32:51 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#define	RED		"\033[1;31m"
#define	BLUE	"\033[1;34m"
#define YELLOW	"\033[1;32m"
#define	RESET	"\033[m"

using std::cout;
using std::string;
using std::endl;

int	main(void)
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	cout << endl;

	cout << "Animal type : " << animal->getType() << " " << endl;
	cout << "Animal type : " << cat->getType() << " " << endl;
	cout << "Animal type : " << dog->getType() << " " << endl;
	cout << "Animal type : " << wrongAnimal->getType() << " " << endl;
	cout << "Animal type : " << wrongCat->getType() << " " << endl;
	cout << endl;
	
	animal->makeSound();
	cat->makeSound(); 
	dog->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	cout << endl;
	
	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}