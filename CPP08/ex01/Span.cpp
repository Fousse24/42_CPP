/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:46:47 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/04 16:33:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "Span.hpp"

using std::string;
using std::stringstream;

using std::vector;

Span::Span( unsigned int n )
{
	_content = vector<int>(n);
	std::fill(_content.begin(), _content.end(), 0);
	_pos = 0;
}

Span::Span( Span const & obj )
{
	*this = obj;
}

Span::~Span()
{
}

Span &	Span::operator=( Span const & obj )
{
	_content = obj._content;
	_pos = obj._pos;
	return *this;
}

const char *	Span::VectorTooSmall::what() const throw()
{
	return ("not enough content in the vector to execute the requested operation"); 
}

void	Span::print( void )
{
	for_each(_content.begin(), _content.end(), Span::fPrint()); 
}

void	Span::addNumberAt( vector<int>::iterator it, int n )
{
	if (it < begin() || it > end())
		throwOutOfRange("addNumberAt: ");
	*it = n;
}

void	Span::addNumber( int const & n )
{
	if (_pos > _content.size())
	{
		throwOutOfRange("addNumber: ");
		return ;
	}
	_content[_pos] = n;
	_pos++;
}

void	Span::addRange( vector<int>::iterator begin, vector<int>::iterator end, int min, int max )
{	
	int		n;
	long	range;

	range = abs((long)max - (long)min) + 1;
	for (vector<int>::iterator it = begin; it <= end; it++)
	{
		n = (rand() % range) + min;
		addNumberAt(it, n);
	}
}

long	Span::shortestSpan( void )
{
	vector<int>	vecTemp;
long			small;
long			dist;

	if (_content.size() <= 1)
		throw Span::VectorTooSmall();
	small = LONG_MAX;
	vecTemp = _content;
	sort(vecTemp.begin(), vecTemp.end());
	for (vector<int>::iterator it = vecTemp.begin(); it < vecTemp.end(); it++)
	{
		dist = abs(*it - *(it + 1));
		if (dist < small)
			small = dist;
	}
	return small;
}

long	Span::longestSpan( void )
{
	int	small = INT_MAX;
	int	big = INT_MIN;

	if (_content.size() <= 1)
		throw Span::VectorTooSmall();
	for (vector<int>::iterator it = begin(); it < end(); it++)
	{
		if (*it <= small)
			small = *it;
		if (*it >= big)
			big = *it;
	}
	return abs((long)big - (long)small);
}

vector<int>::iterator const	Span::begin( void )
{
	return _content.begin();
}

vector<int>::iterator const	Span::end( void )
{
	return _content.end();
}

void	Span::throwOutOfRange( string prefix )
{
	std::stringstream	ss;
	ss << prefix;
	ss << "out of bound ";
	throw std::out_of_range(ss.str());
}

// std::ostream &	operator<<( std::ostream & o, Span const & obj )
// {

// 	return o;
// }
