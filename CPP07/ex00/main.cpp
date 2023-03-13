/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/25 15:27:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"whatever.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;

int	main( void )
{
	int a = 2;
	int b = 3;
	cout << TITLE_COLOR << "SUBJECT PDF EXAMPLE" << RESET_COLOR << endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	cout << endl;

	a = 3;
	b = 6;
	cout << TITLE_COLOR << "VALUES INT : a = 3 | b = 6" << RESET_COLOR << endl;
	cout << "min(a, b) = " << ::min<int>( a, b ) << endl;
	cout << "max(a, b) = " << ::max<int>( a, b ) << endl;
	::swap<int>(a, b);
	cout << "swap(a, b) = " << a << ", " << b << endl;
	cout << endl;

	float g = 5.5f;
	float h = 5.5f;
	cout << TITLE_COLOR << "VALUES FLOAT : c = 5.5f | d = 5.5f" << RESET_COLOR << endl;
	cout << "data address of g and h : " << &g << ", " << &h << endl;
	cout << "min(g, h) and data address of min(g, h) = " << ::min<float>( g, h ) << ", " << &::min<float>( g, h )<< endl;
	cout << "max(g, h) and data address of max(g, h) = " << ::max<float>( g, h ) << ", " << &::max<float>( g, h ) << endl;
	::swap<float>(g, h);
	cout << "swap(g, h) = " << g << ", " << h << endl;
	cout << endl;

	string e("The answer to the universe..?");
	string f("Obviously it's 42");
	cout << TITLE_COLOR << "VALUES STRING : e = \"The answer to the universe..?\" | f = \"Obviously it's 42\"" << RESET_COLOR << endl;
	cout << "min(e, f) = " << ::min<string>( e, f ) << endl;
	cout << "max(e, f) = " << ::max<string>( e, f ) << endl;
	::swap<string>(e, f);
	cout << "swap(e, f) = " << e << ", " << f << endl;
	cout << endl;
	
	return 0;
}