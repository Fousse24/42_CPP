/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:41:25 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/06 16:47:22 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <sstream>

using std::string;

template< typename T >
class MutantStack : public std::stack<T>
{
public:
	/*	
	*	Adding a type to be used in the class.
	*	This is used to send reverse iterators, which will make begin() return the top()
	*/
	typedef typename std::stack<T>::container_type::iterator iterator;
	
	MutantStack<T>() : std::stack<T>()
	{
	};

	MutantStack<T>( MutantStack<T> const & obj ) : std::stack<T>(obj)
	{
	};

	~MutantStack<T>()
	{
	};

	// MutantStack<T> &	operator=( MutantStack<T> const & obj )
	// {
	// 	std::stack<T>::operator=(obj);
	// 	return *this;
	// }

	iterator const	begin( void )
	{			
		return std::stack<T>::c.begin();
	}

	iterator const	end( void )
	{	
		// if (this->size() == 1)
		// 	return std::stack<T>::c.rbegin();
		return std::stack<T>::c.end();
	}
};

#endif
