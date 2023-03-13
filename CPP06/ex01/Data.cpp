/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/23 17:42:04 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	_data1 = 1;
	_data2 = "This is some data";
}

Data::Data( Data const &obj )
{
	*this = obj;
}

Data::~Data()
{
}

Data &	Data::operator=( Data const & obj )
{
	_data1 = obj._data1;
	_data2 = obj._data2;
	return *this;
}

int		Data::getData1() const
{
	return _data1;
}

string	Data::getData2() const
{
	return _data2;
}


std::ostream &	operator<<( std::ostream & o, Data const & obj )
{
	std::cout << "Data: " << obj.getData1() << ", " << obj.getData2() << std::endl;
	return o;
}