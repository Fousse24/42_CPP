/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/23 13:25:11 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>

int	main( void )
{
	std::string		base_str("HI THIS IS BRAIN");
	std::string		*stringPTR;
	std::string		&stringREF = base_str;

	stringPTR = &base_str;

	std::cout << std::endl;
	std::cout << "String (address)\t: " << &base_str << std::endl;
	std::cout << "Pointer (address)\t: " << stringPTR << std::endl;
	std::cout << "Reference (address)\t: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String (value)\t\t: " << base_str << std::endl;
	std::cout << "Pointer (value)\t\t: " << *stringPTR << std::endl;
	std::cout << "Reference (value)\t: " << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}