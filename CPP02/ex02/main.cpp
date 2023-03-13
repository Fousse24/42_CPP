/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/28 13:36:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Fixed.hpp"

int main( void ) 
{
	Fixed z;
	Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << z << std::endl;
	std::cout << ++z << std::endl;
	std::cout << z << std::endl;
	std::cout << z++ << std::endl;
	std::cout << z << std::endl;
	std::cout << y << std::endl;
	std::cout << Fixed::max( z, y ) << std::endl;
	std::cout << std::endl;

	Fixed a( 5 );
	Fixed b( 4.2f );
	Fixed c( -3 );
	Fixed d( -6.765f );
	Fixed e( 5.0f );
	Fixed f( 1.121f );
	Fixed g( 1.128f );
	Fixed const c_n1(1.9f);
	Fixed const c_n2(2.1f);
	Fixed n1(1.9f);
	Fixed n2(2.1f);
	
	std::cout << "a(5) b(4.2) c(-3) d(-6.765) e(5.0) f(1.1233) g(1.1234)" << std::endl;
	
	a = b;
	std::cout << std::endl;
	std::cout << "a = b" << (a = b) << std::endl;
	b = Fixed(1);
	std::cout << "a and b (after b = Fixed(1)) " << a << " " << b << std::endl;
	std::cout << std::endl;


	std::cout << "b + d = " << (b + d) << std::endl;
	std::cout << "b - d = " << (b - d) << std::endl;
	std::cout << "a * e = " << (a * e) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / e = " << (a / e) << std::endl;
	std::cout << "e / d = " << (e / d) << std::endl;
	std::cout << "e / d * d / d * d = " << (e / d * d / d * d) << std::endl;
	std::cout << "(e / d * d / d * d == e) = " << ((e / d * d / d * d) == e) << std::endl;
	std::cout << "(e / d * d / d * d != e) = " << ((e / d * d / d * d) != e) << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;

	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a >= e : " << (a >= e) << std::endl;
	std::cout << "a > e : " << (a > e) << std::endl;
	std::cout << "a < e : " << (a < e) << std::endl;
	std::cout << "a <= e : " << (a <= e) << std::endl;
	std::cout << "f < g : " << (f < g) << std::endl;
	std::cout << "f > g : " << (f > g) << std::endl;
	std::cout << "f <= g : " << (f <= g) << std::endl;
	std::cout << "f >= g : " << (f >= g) << std::endl;
	std::cout << std::endl;
	
	std::cout << "a++ " << a++ << " " << a << std::endl;
	std::cout << "++b " << ++b << " " << b << std::endl;
	std::cout << "c-- " << c-- << " " << c << std::endl;
	std::cout << "--d " << --d << " " << d << std::endl;
	std::cout << std::endl;

	std::cout << "a++ " << a++ << " " << a << std::endl;
	std::cout << "++b " << ++b << " " << b << std::endl;
	std::cout << "c-- " << c-- << " " << c << std::endl;
	std::cout << "--d " << --d << " " << d << std::endl;
	std::cout << std::endl;

	std::cout << "const n1 n2 min " << Fixed::min(c_n1, c_n2) << std::endl;
	std::cout << "const n1 n2 max " << Fixed::max(c_n1, c_n2) << std::endl;
	std::cout << "n1 n2 min " << Fixed::min(n1, n2) << std::endl;
	std::cout << "n1 n2 max " << Fixed::max(n1, n2) << std::endl;
	std::cout << "n1 n2 max == n2 " << (Fixed::max(n1, n2) == n2) << std::endl;
	std::cout << std::endl;

	std::cout << "EPSILON " << powf(2, -8) << std::endl;
	std::cout << "raw EPSILON " << powf(2, -8) * (1 << 8) << std::endl;
	std::cout << std::endl;
	
	return 0;
}