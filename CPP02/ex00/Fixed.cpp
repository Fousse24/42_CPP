/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:27:49 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/28 13:26:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & fpn)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fpn;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_n);
}

void	Fixed::setRawBits( int const raw)
{
	this->fixed_n = raw;
}

Fixed &	Fixed::operator=( Fixed const & fpn )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fpn.getRawBits());

	return *this;
}