/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:55:38 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/28 14:12:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::~Point()
{
}

/*
* I've tried a lot of ways to make it work
* and I've discussed with others to find an elegant solution.
* It's either not possible to make it work safely, or the
* solution is quite obscure and I couldn't find it.
*
* A teammate mentioned const_cast could work, but
* he decided to not use it as it was not shown anywhere
* in our theory, and it's also undefined behavior.
*/
Point	Point::operator=( Point const & )
{
	return *this;
}

Fixed const	&Point::getX( void ) const
{
	return (this->x);
}

Fixed const	&Point::getY( void ) const
{
	return (this->y);
}

std::ostream &	operator<<( std::ostream & o, Point const & i )
{
	o << "P(" << i.getX() << ", " << i.getY() << ")";
	return o;
}

bool	operator==( Point const & p1, Point const & p2 )
{
	if (p1.getX() == p2.getX() && p1.getY() == p2.getY())
		return (true);
	return (false);
}
