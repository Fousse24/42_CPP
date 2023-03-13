/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:57:43 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/25 18:59:24 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

using std::string;

template< typename T >
class Array
{
private:
	T *				_content;
	unsigned int	_size;

public:
	// CONSTRUCTORS
	Array<T>()
	{
		_content = NULL;
		_size = 0;
	};

	Array<T>( unsigned int size )
	{
		if (size > 0)
		{
			_content = new T[size];
			_size = size;
		}
		else
		{
			_content = NULL;
			_size = 0;
		}
	}

	Array<T>( Array<T> const & obj )
	{
		*this = obj;
	}

	// DESTRUCTOR
	~Array<T>()
	{
		if (_content)
			delete [] _content;
	}

	// OVERLOADS
	Array<T> &	operator=( Array<T> const &obj )
	{
		unsigned int	size;

		size = obj.size();
		if (size <= 0)
		{
			_content = NULL;
			_size = 0;
		}
		else
		{
			_content = new T[size];
			if (_content)
			{
				for (unsigned int i = 0; i < size; i++)
					_content[i] = obj[i];
				_size = size;
			}
		}
		return *this;
	}

	T &	operator[]( unsigned int index ) const
	{
		if (index >= this->size())
		{
			string	errorMsg;

			errorMsg = "the given index("+ std::to_string(index) + ") ";
			errorMsg.append("is out of bound of Array of size(" + std::to_string(this->size()) + ").");
			throw std::out_of_range(errorMsg);
		}
		return _content[index];
	}

	// FUNCTIONS
	unsigned int	size( void ) const
	{
		return _size;
	}
};

#endif