/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:55:40 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/25 14:21:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
	Fixed	&operator ++ ( void );
	Fixed	operator ++ ( int );
	Fixed	&operator -- ( void );
	Fixed	operator -- ( int );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed		&min( Fixed & fpn1, Fixed & fpn2);
	static Fixed const	&min( Fixed const & fpn1, Fixed const & fpn2);
	static Fixed		&max( Fixed & fpn1, Fixed & fpn2);
	static Fixed const	&max( Fixed const & fpn1, Fixed const & fpn2);

};

std::ostream	&operator << ( std::ostream & o, Fixed const & fpn );
Fixed			operator - ( Fixed const & fpn1, Fixed const & fpn2 );
Fixed			operator + ( Fixed const & fpn1, Fixed const & fpn2 );
Fixed			operator * ( Fixed const & fpn1, Fixed const & fpn2 );
Fixed			operator / ( Fixed const & fpn1, Fixed const & fpn2 );
bool			operator > ( Fixed const & fpn1, Fixed const & fpn2 );
bool			operator < ( Fixed const & fpn1, Fixed const & fpn2 );
bool			operator >= ( Fixed const & fpn1, Fixed const & fpn2 );
bool			operator <= ( Fixed const & fpn1, Fixed const & fpn2 );
bool			operator == ( Fixed const & fpn1, Fixed const & fpn2 );
bool			operator != ( Fixed const & fpn1, Fixed const & fpn2 );

#endif