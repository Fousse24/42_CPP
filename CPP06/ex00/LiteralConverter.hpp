/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LiteralConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:40:20 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/28 15:58:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LITERALCONVERTER_HPP
#define	LITERALCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include <limits>

using std::string;

class LiteralConverter
{
private:
	string	_literal;
	enum eConv
	{
		CONV_CHAR,
		CONV_INT,
		CONV_FLT,
		CONV_DBL,
		CONV_NONE
	};
	eConv	_type;
	
	char	_c;
	double	_dbl;
	float	_flt;
	int		_int;
	
	bool	_toI;
	bool	_toC;
	bool	_toF;
	bool	_toD;

	void	findType( string const & literal );

	void	toChar( string const & literal );
	void	toDouble( string const & literal );
	void	toFloat( string const & literal );
	void	toInt( string const & literal );

public:
	LiteralConverter();
	LiteralConverter( LiteralConverter const & obj );
	~LiteralConverter();
	LiteralConverter &	operator=( LiteralConverter const &obj );

	void	convert( string const & literal );

	static bool	isDigit( char const & c );
	static bool	isNumber( string const & str );
	static bool	isLiteralChar( string const & str );
	static bool	isDecimal( string const & str );
	static bool	isPseudoFlt( string const & str );
	static bool	isPseudoDbl( string const & str );

	static bool	isChar( string const & literal );
	static bool	isDouble( string const & literal );
	static bool	isFloat( string const & literal );
	static bool	isInt( string const & literal );

	void	printChar( void );
	void	printDouble( void );
	void	printFloat( void );
	void	printInt( void );
	void	printAll( void );
};

#endif
