/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:42:06 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/23 17:42:06 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

using std::string;

class Data
{
private:
	int		_data1;
	string	_data2;

public:
	Data();
	Data( Data const &obj );
	~Data();

	Data &	operator=( Data const &obj );

	int		getData1( void ) const;
	string	getData2( void ) const;
};

std::ostream	&operator << ( std::ostream & o, Data const & obj );

#endif