/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:50:36 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/16 13:16:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Karen.hpp"
#include	<iostream>

Karen::Karen(){}

Karen::~Karen(){}

void	Karen::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Spoiler alert, I don't like the theme of this exercise." << std::endl;
}

void	Karen::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I'm debating telling bocal that this exercise is insulting and degrading." << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I swear, I'm gonna whine to them so much they'll have to change it!" << std::endl;
}

void	Karen::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "THOU WILL RUE THY DAY THINE MADE THIS PATRIARCHAL EXERCISE! THY WORLD SHALL BURN!!";
	std::cout << " \033[1;31m[  ̸̨̧͔̾̓́̈͝͝Y̶̱̼̦͂̔O̴̻͊Ų̴̨̺̤̻̦̟̭̣̩̈́͛͌̆̒͘ ̶̥̹͌̒͑̃͘D̴̛͚̔̍̓̅̒͑͒̿̒͝Ỉ̴̫̩̦̗̙͈Ẽ̷̡͎̳̓̀̀̓̓͗̿͋̔̾Ḋ̸̞̗̯̭͙̞̣͖̖͉̈́̔̊̈́ͅ ]\033[0m" << std::endl;
}

void	Karen::complain( std::string level )
{
	int	log = 0;

	if (!level.compare("DEBUG"))
		log = 1;
	if (!level.compare("INFO"))
		log = 2;
	if (!level.compare("WARNING"))
		log = 3;
	if (!level.compare("ERROR"))
		log = 4;
	switch (log)
	{
		case 1:
			this->debug();
			std::cout << std::endl;
		case 2:
			this->info();
			std::cout << std::endl;
		case 3:
			this->warning();
			std::cout << std::endl;
		case 4:
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}