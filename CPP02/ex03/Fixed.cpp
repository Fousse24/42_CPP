/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:27:39 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/25 16:46:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
using std::cout;

Fixed::Fixed() : fixed_n(0)
{
}

Fixed::Fixed( int const & n )
{
	fixed_n = (int)(n * (1 << bits));
}

Fixed::Fixed( float const & n )
{
	fixed_n = roundf((n * (1 << bits)));
}

Fixed::~Fixed()
{
}

Fixed::Fixed( Fixed const & fpn)
{
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

Fixed &	Fixed::min( Fixed & fpn1, Fixed & fpn2 )
{
	if (fpn1 < fpn2)
		return (fpn1);
	return (fpn2);
}

Fixed &	Fixed::max( Fixed & fpn1, Fixed & fpn2 )
{
	if (fpn1 > fpn2)
		return (fpn1);
	return (fpn2);
}

Fixed const &	Fixed::min( Fixed const & fpn1, Fixed const & fpn2 )
{
	if (fpn1 < fpn2)
		return (fpn1);
	return (fpn2);
}

Fixed const &	Fixed::max( Fixed const & fpn1, Fixed const & fpn2 )
{
	if (fpn1 > fpn2)
		return (fpn1);
	return (fpn2);
}

Fixed &	Fixed::operator=( Fixed const & fpn )
{
	setRawBits(fpn.getRawBits());

	return (*this);
}

Fixed	&Fixed::operator++( void )
{
	fixed_n += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed fixed = *this;
	++*this;
	return (fixed);
}

Fixed	&Fixed::operator--( void )
{
	fixed_n -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed fixed = *this;
	--*this;
	return (fixed);
}

std::ostream &	operator<<( std::ostream & o, Fixed const & fpn )
{
	o << fpn.toFloat();
	return (o);
}

Fixed	operator+( Fixed const & fpn1, Fixed const & fpn2 )
{
	Fixed fixed;

	fixed.setRawBits((fpn1.getRawBits() + fpn2.getRawBits()));
	return (fixed);
}

Fixed	operator-( Fixed const & fpn1, Fixed const & fpn2 )
{
	Fixed fixed;

	fixed.setRawBits((fpn1.getRawBits() - fpn2.getRawBits()));
	return (fixed);
}

Fixed	operator*( Fixed const & fpn1, Fixed const & fpn2 )
{
	float	f;

	f = fpn1.toFloat() * fpn2.toFloat();
	Fixed fixed(f);
	return (fixed);
}

Fixed	operator/( Fixed const & fpn1, Fixed const & fpn2 )
{
	float	f;

	f = fpn1.toFloat() / fpn2.toFloat();
	Fixed fixed(f);
	return (fixed);
}

bool	operator>( Fixed const & fpn1, Fixed const & fpn2 )
{
	long diff;

	diff = fpn1.getRawBits() - fpn2.getRawBits();
	if (diff > 0 && fpn1 != fpn2)
		return (true);
	return (false);
}

bool	operator<( Fixed const & fpn1, Fixed const & fpn2 )
{
	long diff;

	diff = fpn1.getRawBits() - fpn2.getRawBits();
	if (diff < 0 && fpn1 != fpn2)
		return (true);
	return (false);
}

bool	operator>=( Fixed const & fpn1, Fixed const & fpn2 )
{
	long diff;

	diff = fpn1.getRawBits() - fpn2.getRawBits();
	if (diff > 0 || fpn1 == fpn2)
		return (true);
	return (false);
}

bool	operator<=( Fixed const & fpn1, Fixed const & fpn2 )
{
	long diff;

	diff = fpn1.getRawBits() - fpn2.getRawBits();
	if (diff < 0 || fpn1 == fpn2)
		return (true);
	return (false);
}

bool	operator==( Fixed const & fpn1, Fixed const & fpn2 )
{
	long diff;

	diff = fpn1.getRawBits() - fpn2.getRawBits();
	if (diff >= -1 && diff <= 1)
		return (true);
	return (false);
}

bool	operator!=( Fixed const & fpn1, Fixed const & fpn2 )
{
	if (fpn1 == fpn2)
		return (false);
	return (true);
}