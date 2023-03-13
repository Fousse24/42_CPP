/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:19:40 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/10 16:41:29 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

#define	RED		"\033[1;31m"
#define	BLUE	"\033[1;34m"
#define YELLOW	"\033[1;33m"
#define	RESET	"\033[m"
#define ANIMAL_N	6

using std::cout;
using std::string;
using std::endl;

int	main(void)
{
	Animal	*animals[6];
	Animal	*animals_copy[6];
	Cat		cat;
	Dog		dog;
	Cat		cat_copy;
	Dog		dog_copy;

	cout << YELLOW << "-Initialization of " << ANIMAL_N << " animals" << RESET << endl;
	for(int i = 0; i < ANIMAL_N / 2; i++)
		animals[i] = new Dog();
	for(int i = ANIMAL_N / 2; i < ANIMAL_N; i++)
		animals[i] = new Cat();
	cout << endl;

	cout << YELLOW << "-Copy constructor of " << ANIMAL_N << " animals" << RESET << endl;
	for(int i = 0; i < ANIMAL_N / 2; i++)
		animals_copy[i] = new Dog(*(Dog *)animals[i]);
	for(int i = ANIMAL_N / 2; i < ANIMAL_N; i++)
		animals_copy[i] = new Cat(*(Cat *)animals[i]);
	cout << endl;

	cout << YELLOW << "-Delete of original, copy array and assignment" << RESET << endl;
	for(int i = 0; i < ANIMAL_N; i++)
	{
		delete animals[i];
		delete animals_copy[i];
	}
	//delete animal_assign;
	cout << endl;

	cout << YELLOW << "-Assignment overload tests " << RESET << endl;
	cat_copy = cat;
	dog_copy = dog;
	Cat	lateCat = cat;
	cout << endl;
	return 0;
}