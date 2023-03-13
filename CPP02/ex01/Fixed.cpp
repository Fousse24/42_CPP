/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:28:03 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/12 13:28:51 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
using std::cout;

Fixed::Fixed() : fixed_n(0)
{
	cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const & n )
{
	cout << "Int constructor called" << std::endl;
	fixed_n = (int)(n * (1 << bits));
}

Fixed::Fixed( float const & n )
{
	cout << "Float constructor called" << std::endl;
	fixed_n = roundf((n * (1 << bits)));
}

Fixed::~Fixed()
{
	cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & fpn)
{
	cout << "Copy constructor called" << std::endl;
	*this = fpn;
}

int		Fixed::getRawBits( void ) const
{
	return (this->fixed_n);
}

void	Fixed::setRawBits( int const raw)
{
	fixed_n = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)fixed_n / (float)(1 << bits));
}

int		Fixed::toInt( void ) const
{
	return roundf(((float)fixed_n / (float)(1 << bits)));
}

Fixed &	Fixed::operator=( Fixed const & fpn )
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fpn.fixed_n);

	return *this;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & fpn )
{
	o << fpn.toFloat();
	return (o);
}