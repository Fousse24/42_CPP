/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/25 19:13:17 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"Array.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;


int	main( void )
{
	unsigned int	i;

	cout << TITLE_COLOR << "ACCESSING AN EMPTY ARRAY/INVALID ARRAY INDEX" << RESET_COLOR << endl;
	Array<int>	empty;
	try
	{
		cout << empty[0] << endl;
	}
	catch(const std::exception& e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
	
	cout << TITLE_COLOR << "CREATING AND PRINTING AN Array<int>" << RESET_COLOR << endl;
	Array<int>	intArr(10);
	for (i = 0; i < intArr.size(); i++)
		intArr[i] = static_cast<int>(i + 1);
	
	for (i = 0; i < intArr.size(); i++)
		cout << intArr[i] << endl;
	cout << endl;

	cout << TITLE_COLOR << "CREATING AND PRINTING AN Array<str>" << RESET_COLOR << endl;
	Array<string>	strArr(3);
	strArr[0] = "This";
	strArr[1] = "is";
	strArr[2] = "something";
	for (i = 0; i < strArr.size(); i++)
		cout << strArr[i] << endl;
	cout << endl;

	cout << TITLE_COLOR << "COPY AND ASSIGNMENT TESTING" << RESET_COLOR << endl;
	Array<string>	strArrCopy(strArr);
	Array<string>	strArrAssign = strArrCopy;
	strArrCopy[0] = "I";
	strArrCopy[1] = "Am";
	strArrCopy[2] = "Copy";
	strArrAssign[0] = "and";
	strArrAssign[1] = "me, ";
	strArrAssign[2] = "I'm mister assignment";
	for (i = 0; i < strArr.size(); i++)
		cout << strArr[i] << endl;
	cout << endl;
	for (i = 0; i < strArrCopy.size(); i++)
		cout << strArrCopy[i] << endl;
	cout << endl;
	for (i = 0; i < strArrAssign.size(); i++)
		cout << strArrAssign[i] << endl;
	cout << endl;

	cout << TITLE_COLOR << "ACCESSING AN OUT OF BOUND ARRAY INDEX" << RESET_COLOR << endl;
	try
	{
		cout << strArr[3] << endl;

	}
	catch(const std::exception& e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
		
	
	
	return 0;
}