/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/06/29 16:52:55 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<iomanip>
#include	<string>
#include	"LiteralConverter.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;

int	main(int argc, char **argv)
{
	LiteralConverter	conv;
	string				literal;

	if (argc != 2)
	{
		cout << "Error: the program needs exactly 1 argument." << endl;
		return 0;
	}
	literal = argv[1];
	if (literal.compare("test"))
	{
		conv.convert(literal);
		conv.printAll();
	}
	else
	{
		conv.convert(string("+inf"));
		conv.printAll();
		cout << endl;

		conv.convert(string("-inf"));
		conv.printAll();
		cout << endl;

		conv.convert(string("nan"));
		conv.printAll();
		cout << endl;

		conv.convert(string("+inff"));
		conv.printAll();
		cout << endl;

		conv.convert(string("-inff"));
		conv.printAll();
		cout << endl;

		conv.convert(string("nanf"));
		conv.printAll();
		cout << endl;

		conv.convert(string("-2147483648"));
		conv.printAll();
		cout << endl;

		conv.convert(string("-2147483649"));
		conv.printAll();
		cout << endl;

		conv.convert(string("0"));
		conv.printAll();
		cout << endl;

		conv.convert(string("70"));
		conv.printAll();
		cout << endl;

		conv.convert(string("c"));
		conv.printAll();
		cout << endl;

	}
	
	

	//cout << std::fixed << std::setprecision(5) << d << endl;
	return 0;
}
