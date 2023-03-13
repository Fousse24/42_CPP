/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/23 17:47:15 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"Data.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;

uintptr_t	serialize( Data * ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *	deserialize( uintptr_t ptr )
{
	return (reinterpret_cast<Data *>(ptr));
}

int	main()
{
	Data		data;
	uintptr_t	ptr_int;
	Data *		ptr;

	cout << data;
	cout << "Base data address: \t" << &data << endl;
	ptr_int = serialize(&data);
	cout << "Serialized address: \t" << ptr_int << endl;
	ptr = deserialize(ptr_int);
	cout << "Deserialized address: \t" << ptr << endl;
	cout << "Value pointed by <ptr>: " << *ptr << endl;
	return 0;
}