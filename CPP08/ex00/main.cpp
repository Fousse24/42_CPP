/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:40:19 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/03 17:51:59 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "easyfind.hpp"

using std::cout;
using std::endl;

int	main( int argc, char **argv )
{
	std::vector<int>	vectInt;
	std::list<int>		listInt;
	std::string			str("32"); // 50 or 51 should work

	cout << "\033[1;32mTest: \targuments are added into a list and a vector." << endl;
	cout << "\tThe last argument is the value that will be searched." << endl;
	cout << "\tIt will also search in a string, but its content is hardcoded." << endl;

	cout << endl << "\033[1;32m\tif only 1 argument is entered, it will be searched in a list of 100000 odd numbers.\033[0m" << endl;

	if (argc <= 1)
		return 0;
	if (argc > 2)
	{
		// Int vector test
		for( int i = 1; i < argc - 1; i++)
		{
			try
			{
				vectInt.push_back(std::stoi(std::string(argv[i])));
				listInt.push_back(std::stoi(std::string(argv[i])));
			}
			catch( std::exception & e )
			{
				cout << "One of the arguments is invalid: " << e.what() << endl;
				return 0;
			}
		}
	}
	else if (argc == 2)
	{
		try
		{
			for( int i = 1; i <= 200000; i += 2)
			{
				
				vectInt.push_back(i);
				listInt.push_back(i);
			}
			
		}
		catch( std::exception & e )
		{
			cout << "One of the arguments is invalid: " << e.what() << endl;
			return 0;
		}
	}
	try
	{
		if (easyfind(vectInt, std::stoi(std::string(argv[argc - 1]))))
			cout << "Found in vector!" << endl;
		else
			cout << "Not found in vector!" << endl;
		if (easyfind(listInt, std::stoi(std::string(argv[argc - 1]))))
			cout << "Found in list!" << endl;
		else
			cout << "Not found in list!" << endl;
		if (easyfind(str, std::stoi(std::string(argv[argc - 1]))))
			cout << "Found in string!" << endl;
		else
			cout << "Not found in string!" << endl;
	}
	catch( std::exception & e )
	{
		cout << "Value can't be converted to an int:  " << e.what() << endl;
		return 0;
	}
	return 0;
}
