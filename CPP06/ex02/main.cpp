/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/23 18:15:40 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"Base.hpp"
#include	"A.hpp"
#include	"B.hpp"
#include	"C.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;

Base *	generate( void )
{
	srand((unsigned int)time(0));
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (new Base());
	}
}

void	identify( Base * p )
{
	if (dynamic_cast<A*>(p))
		cout << "Received object is of type A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "Received object is of type B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "Received object is of type C" << endl;
	else
		cout << "Received object is unknown" << endl;
}

void	identify( Base & p )
{
	Base	b;
	try 
	{ 
		b = dynamic_cast<A&>(p); 
		cout << "Received object is of type A" << endl;
		return;
	}
	catch (const std::exception &e) {}
	try 
	{ 
		b = dynamic_cast<B&>(p); 
		cout << "Received object is of type B" << endl;
		return;
	}
	catch (const std::exception &e) {}
	try 
	{ 
		b = dynamic_cast<C&>(p); 
		cout << "Received object is of type C" << endl;
		return;
	}
	catch (const std::exception &e) {}
	cout << "Received object is unknown" << endl;
}


int	main()
{
	Base *	base;

	base = generate();
	cout << "--- As pointer" << endl;
	identify(base);
	cout << endl;
	cout << "--- As reference" << endl;
	identify(*base);
	delete base;
	return 0;
}