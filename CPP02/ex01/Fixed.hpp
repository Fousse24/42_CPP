/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:20:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 08:27:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINTNUM_HPP
#define FIXEDPOINTNUM_HPP

#include <iostream>
#include <cmath>

// Epsilon = powf(2, -bits)

class Fixed
{
private:
	int fixed_n;
	static int const bits = 8;

public:
    Fixed();
	Fixed( int const & n);
	Fixed( float const & n);
	Fixed( Fixed const & fpn);
    ~Fixed();
	Fixed	&operator = ( Fixed const & fpn );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream	&operator << ( std::ostream & o, Fixed const & fpn );

#endif