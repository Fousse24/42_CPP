/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:41:25 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/04 16:30:26 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using std::string;
using std::vector;

class Span
{
private:
	vector<int>		_content;
	unsigned int	_pos;

	Span() : _content(vector<int>(0)), _pos(0) {};
	
	struct fPrint
	{
		void operator()(int const & n) const { std::cout << n << std::endl; }
	};
	
	void	addNumberAt( vector<int>::iterator it, int n );
	void	throwOutOfRange( string prefix );

public:
	Span( unsigned int n );
	Span( Span const & obj );
	~Span();

	Span &	operator=( Span const & obj );

	class VectorTooSmall : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};

	void	addNumber( int const & n );
	void	addRange( vector<int>::iterator begin, vector<int>::iterator end, int min, int max );
	long	shortestSpan( void );
	long	longestSpan( void );
	void	print( void );

	vector<int>::iterator const	begin( void );
	vector<int>::iterator const	end( void );

	vector<int> const &		getContent( void ) const;
	unsigned int const &	getMaxSize( void ) const;
};

// std::ostream	&operator << ( std::ostream & o, Span const & obj );

#endif
