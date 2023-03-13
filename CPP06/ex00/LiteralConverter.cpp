/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LiteralConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:59:35 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/28 16:08:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LiteralConverter.hpp"
using std::cout;
using std::endl;

LiteralConverter::LiteralConverter()
{
	_type = CONV_NONE;
	_toI = false;
	_toC = false;
	_toF = false;
	_toD = false;
}

LiteralConverter::LiteralConverter( LiteralConverter const & obj )
{
	*this = obj;
}

LiteralConverter::~LiteralConverter()
{
}

LiteralConverter &	LiteralConverter::operator=( LiteralConverter const &obj )
{
	_type = obj._type;
	_c = obj._c;
	_int = obj._int;
	_dbl = obj._dbl;
	_flt = obj._flt;
	
	_toC = obj._toC;
	_toI = obj._toI;
	_toD = obj._toD;
	_toF = obj._toF;
	return *this;
}

void	LiteralConverter::findType( string const & literal )
{
	bool	isDecimal;

	if (!isLiteralChar(literal) && !isNumber(literal) && !isPseudoFlt(literal) && !isPseudoDbl(literal))
		return ;
	isDecimal = this->isDecimal(literal);
	if (!isDecimal && (isChar(literal) || isLiteralChar(literal)))
		_type = CONV_CHAR;
	else if (!isDecimal && isInt(literal))
		_type = CONV_INT;
	else if (isFloat(literal))
		_type = CONV_FLT;
	else if (isDouble(literal))
		_type = CONV_DBL;
}

void	LiteralConverter::convert( string const & literal )
{
	_literal = literal;
	findType(_literal);
	switch (_type)
	{
		case CONV_CHAR:
			toChar(literal);
			break;
		case CONV_INT:
			toInt(literal);
			break;
		case CONV_FLT:
			toFloat(literal);
			break;
		case CONV_DBL:
			toDouble(literal);
			break;
		default:
			break;
	}
}

bool	LiteralConverter::isDigit( char const & c )
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool	LiteralConverter::isLiteralChar( string const & str )
{
	if (str.size() == 1 && str[0] >= 32 && str[0] <= 126)
		return true;
	return false;
}

bool	LiteralConverter::isNumber( string const & str )
{
	bool	dot = false;
	size_t	i = 0;
	
	if (!(str.back() == 'f' && str.size() > 1) && !isDigit(str.back()))
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < str.length())
	{
		if (!isDigit(str[i]))
		{
			if (str[i] == '.' && !dot)
				dot = true;
			else if (str[i] == 'f' && i == (str.length() - 1))
				break;
			else
				return false;
		}
		i++;
	}
	return true;
}

bool	LiteralConverter::isDecimal( string const & str )
{
	bool	dot = false;
	bool	isZero = true;
	size_t	i = 0;

	if (!(str.back() == 'f' && str.size() > 1) && !isDigit(str.back()))
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;	
	while (i < str.length())
	{
		if (!isDigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (dot)
					return false;
				else
					dot = true;
			}
			else if (str[i] == 'f')
			{
				i++;
				break;
			}
			else
				return false;
		}
		else if (str[i] != '0' && dot)
			isZero = false;
		i++;
	}
	if (i != str.length() || !dot || isZero)
		return false;
	return true;
}

bool	LiteralConverter::isPseudoFlt( string const & literal )
{
	if (!literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("nanf"))
		return true;
	return false;
}

bool	LiteralConverter::isPseudoDbl( string const & literal )
{
	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan"))
		return true;
	return false;
}

bool	LiteralConverter::isChar( string const & literal )
{
	int	toInt;

	if (!isInt(literal))
		return false;
	toInt = std::stoi(literal);
	if (toInt >= 0 && toInt <= 255)
		return true;
	return false;
}

bool	LiteralConverter::isDouble( string const & literal )
{
	try
	{
		if (isPseudoDbl(literal))
			return true;
		std::stod(literal);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool	LiteralConverter::isFloat( string const & literal )
{
	double	d;

	try
	{
		if (isPseudoFlt(literal))
			return true;
		d = std::stod(literal);
		if (d <= std::numeric_limits<float>::max() && d >= std::numeric_limits<float>::lowest())
			return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return false;
}

bool	LiteralConverter::isInt( string const & literal )
{
	try
	{
		std::stoi(literal);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

void	LiteralConverter::toChar( string const & literal )
{
	int		toInt;

	if (isLiteralChar(literal))
	{
		_c = literal[0];
	}
	else
	{
		try 
		{ 
			toInt = std::stoi(literal);
			_c = static_cast<char>(toInt);
		}
		catch ( const std::exception& e ) {}
	}
	_int = static_cast<int>(_c);
	_flt = static_cast<float>(_c);
	_dbl = static_cast<double>(_c);
	
	_toC = true;
	_toI = true;
	_toF = true;
	_toD = true;
}

void	LiteralConverter::toInt( string const & literal )
{
	try { _int = std::stoi(literal); }
	catch ( const std::exception& e ) {}
	_flt = static_cast<float>(_int);
	_dbl = static_cast<double>(_int);

	_toC = false;
	_toI = true;
	_toF = true;
	_toD = true;
}

void	LiteralConverter::toFloat( string const & literal )
{
	try { _flt = (float)std::stod(literal); }
	catch ( const std::exception& e ) {}
	_dbl = static_cast<double>(_flt);

	_toC = false;
	_toI = false;
	_toF = true;
	_toD = true;
}

void	LiteralConverter::toDouble( string const & literal )
{
	try { _dbl = std::stod(literal); }
	catch ( const std::exception& e ) {}
	
	_toF = false;
	_toC = false;
	_toI = false;
	_toD = true;

	if (isPseudoDbl(literal))
	{
		_toF = true;
		_flt = static_cast<float>(_dbl);
	}
}

void	LiteralConverter::printChar( void )
{
	std::stringstream	ss;
	string				s;

	if (_toC)
	{
		if ((int)_c < 32 || (int)_c > 126)
			ss << "non displayable";
		else
			ss << _c;
	}
	else
		ss << "impossible";
	s = ss.str();
	cout << "char: " << s << endl;
}

void	LiteralConverter::printInt( void )
{
	std::stringstream	ss;
	string				s;

	if (_toI)
	{
		ss << _int;
	}
	else
		ss << "impossible";
	s = ss.str();
	cout << "int: " << s << endl;
}

void	LiteralConverter::printFloat( void )
{
	std::stringstream	ss;
	string				s;

	if (_toF)
	{
		ss << _flt;
		if (fmod(_flt, 1.0f) == 0.0f)
			ss << ".0";
		ss << "f";
	}
	else
		ss << "impossible";
	s = ss.str();
	cout << "float: " << s << endl;
}

void	LiteralConverter::printDouble( void )
{
	std::stringstream	ss;
	string				s;

	if (_toD)
	{
		ss << _dbl;
		if (fmod(_flt, 1.0f) == 0.0f && !isPseudoDbl(_literal) && !isPseudoFlt(_literal))
			ss << ".0";
	}
	else
		ss << "impossible";
	s = ss.str();
	cout << "double: " << s << endl;
}

void	LiteralConverter::printAll( void )
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}
