/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:10 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/03 15:02:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using	std::cout;
using	std::endl;

Brain::Brain()
{
	cout << B_COLOR << "A brain has become juicy and functional!" << B_RESET << endl;
}

Brain::Brain( const Brain & obj )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	cout << B_COLOR << "A brain has been cloned!!" << B_RESET << endl;
}

Brain::~Brain()
{
	cout << B_COLOR << "A brain has been splattered everywhere. Praise the brain juice!." << B_RESET << endl;
}

Brain	&Brain::operator=( Brain const & obj )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}
