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

Karen::Karen()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	f[0] = &Karen::debug;
	f[1] = &Karen::info;
	f[2] = &Karen::warning;
	f[3] = &Karen::error;
}

Karen::~Karen()
{

}

void	Karen::debug( void )
{
	std::cout << "Spoiler alert, I don't like the theme of this exercise." << std::endl;
}

void	Karen::info( void )
{
	std::cout << "I'm debating telling bocal that this exercise is insulting and degrading." << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "I swear, I'm gonna whine to them so much they'll have to change it!" << std::endl;
}

void	Karen::error( void )
{
	std::cout << "THEY WILL RUE THE DAY THEY MADE THIS PATRIARCHAL EXERCISE! THE WORLD SHALL BURN!!";
	std::cout << " \033[1;31m[  ̸̨̧͔̾̓́̈͝͝Y̶̱̼̦͂̔O̴̻͊Ų̴̨̺̤̻̦̟̭̣̩̈́͛͌̆̒͘ ̶̥̹͌̒͑̃͘D̴̛͚̔̍̓̅̒͑͒̿̒͝Ỉ̴̫̩̦̗̙͈Ẽ̷̡͎̳̓̀̀̓̓͗̿͋̔̾Ḋ̸̞̗̯̭͙̞̣͖̖͉̥̮̈́̔̊̈́͘ͅ ]\033[0m" << std::endl;
}

void	Karen::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (!levels[i].compare(level))
		{
			return (this->*f[i])();
		}
	}
	return ;
}