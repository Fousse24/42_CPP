/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/25 15:50:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"iter.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;

class IterTest
{
private:
	string	_name;
public:
	IterTest(string name) { _name = name; };
	~IterTest() {};

	string const &	getName( void ) const { return _name; };
};

void	print_object_name( IterTest const & obj )
{
	cout << obj.getName() << endl;
}

void	sum_it( int const & n )
{
	static int	sum;
	sum += n;
	cout << sum << endl;
}

void	print_it( string const & str )
{
	cout << str << endl;
}

int	main( void )
{
	cout << TITLE_COLOR << "Iter string array : print every elememnts" << RESET_COLOR << endl;
	string str_arr[4] = { "This", "is", "an", "array" };
	::iter(str_arr, 4, print_it);
	cout << endl;

	cout << TITLE_COLOR << "Iter int array : sum every elements in a static int" << RESET_COLOR << endl;
	int int_arr[5] = { 4, 3, 2, 1, 5 };
	::iter(int_arr, 5, sum_it);
	cout << endl;

	cout << TITLE_COLOR << "Iter class array : print the name of every IterTest objects" << RESET_COLOR << endl;
	IterTest iter_arr[3] = { IterTest("poutine_stjean"), IterTest("mikastiv"), IterTest("armorine") };
	::iter(iter_arr, 3, print_object_name);
	cout << endl;

	cout << TITLE_COLOR << "Iter int array : use the some_function template" << RESET_COLOR << endl;
	::iter(int_arr, 5, ::some_function);
	cout << endl;
	
	return 0;
}