/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:40:19 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/04 16:36:05 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Span.hpp"

using std::cout;
using std::endl;
using std::vector;

//-----Subject test
// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }

int	main( int argc, char **argv )
{
	Span	span(5);
	Span	spanRange(20);
	Span	spanGigantic(100000);
	vector<int>::iterator	it;

	srand(time(0));
	try
	{
		cout << "\033[1;32mFILL A RANGE AND PRINT SPAN OF 20\033[0m" << endl;
		vector<int>::iterator	begin = spanRange.begin() + 10;
		vector<int>::iterator	end = spanRange.end() - 5;

		spanRange.addRange(begin, end, -200000, 200000);
		// spanRange.addRange(begin, end, -2, 2);
		spanRange.print();
		cout << endl;

		cout << "\033[1;32mFILL AND PRINT SPAN OF 5 (OR OF GIVEN SIZE (ARG 1) AND GIVEN RANGE (ARG 2)\033[0m" << endl;
		if (argc >= 2)
			span = Span(std::stoi(argv[1]));
		for (it = span.begin(); it <= span.end(); it++)
		{
			if (argc >=3 )
				span.addNumber(rand() % std::stoi(argv[2]));
			else
				span.addNumber(rand() % 50 - 25);
		}

		span.print();
		cout << endl;

		cout << "\033[1;32mLONGEST SPAN OF PREVIOUS RANGE\033[0m" << endl;
		cout << span.longestSpan();

		cout << endl << "\033[1;32mSHORTEST SPAN OF PREVIOUS RANGE\033[0m" << endl;
		cout << span.shortestSpan();

		spanGigantic.addRange(spanGigantic.begin(), spanGigantic.end(), INT_MIN, INT_MAX);
		// spanGigantic.addRange(spanGigantic.begin(), spanGigantic.end(), -100, 100);
		cout << endl << "\033[1;32mLONGEST SPAN OF 100 000 numbers between INT_MIN and MAX\033[0m" << endl;
		cout << spanGigantic.longestSpan() << endl;

		cout << "\033[1;32mSHORTEST SPAN OF 100 000 numbers between INT_MIN and MAX\033[0m" << endl;
		cout << spanGigantic.shortestSpan() << endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	

	return 0;
}
