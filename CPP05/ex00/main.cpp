/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/13 18:31:37 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"Bureaucrat.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;

int	main()
{
	Bureaucrat tok("Tok", 14);
	Bureaucrat laube("Laube", 1);
	Bureaucrat seb("Sébas", 150);
	
	cout << TITLE_COLOR << "TEST SETUP" << RESET_COLOR << endl;
	cout << "Name\tGrade" << endl;
	cout << "Tok\t14" << endl;
	cout << "Laube\t1" << endl;
	cout << "Sébas\t150" << endl;
	cout << "Collet\t151" << endl;
	cout << "Justine\t0" << endl;
	
	cout << endl << TITLE_COLOR << "CREATION" << RESET_COLOR << endl;
	try	{ Bureaucrat collet("Collet", 151); }
	catch (std::exception & e)
	{
		cout << "Exception during creation of Collet: " << e.what() << endl;
	}
	try	{ Bureaucrat collet("Justine", 0); }
	catch (std::exception & e)
	{
		cout << "Exception during creation of Justine: " << e.what() << endl;
	}
	
	cout << endl << TITLE_COLOR << "PRE-PROMOTION" << RESET_COLOR << endl;
	cout << laube << tok << seb << endl;

	try	{ tok.promote(); }
	catch (std::exception & e)
	{
		cout << "Exception during promotion of Tok: " << e.what() << endl;
	}
	try	{ laube.promote(); }
	catch (std::exception & e)
	{
		cout << "Exception during promotion of Laube: " << e.what() << endl;
	}
	try	{ seb.promote(); }
	catch (std::exception & e)
	{
		cout << "Exception during promotion of Sébas: " << e.what() << endl;
	}

	cout << endl << TITLE_COLOR << "POST-PROMOTION" << RESET_COLOR << endl;
	cout << laube << tok << seb << endl;

	cout << endl << TITLE_COLOR << "DEMOTION" << RESET_COLOR << endl;
	try	{ tok.demote(); }
	catch (std::exception & e)
	{
		cout << "Exception during demotion of Tok: " << e.what() << endl;
	}
	try	{ laube.demote(); }
	catch (std::exception & e)
	{
		cout << "Exception during demotion of Laube: " << e.what() << endl;
	}
	try	{ seb.demote(); }
	catch (std::exception & e)
	{
		cout << "Exception during demotion of Sébas: " << e.what() << endl;
	}

	cout << endl << TITLE_COLOR << "POST-DEMOTION" << RESET_COLOR << endl;
	cout << laube << tok << seb << endl;

	cout << endl << TITLE_COLOR << "DEMOTION" << RESET_COLOR << endl;
	try	{ tok.demote(); }
	catch (std::exception & e)
	{
		cout << "Exception during demotion of Tok: " << e.what() << endl;
	}
	try	{ laube.demote(); }
	catch (std::exception & e)
	{
		cout << "Exception during demotion of Laube: " << e.what() << endl;
	}
	try	{ seb.demote(); }
	catch (std::exception & e)
	{
		cout << "Exception during demotion of Sébas: " << e.what() << endl;
	}

	cout << endl << TITLE_COLOR << "POST-DEMOTION" << RESET_COLOR << endl;
	cout << laube << tok << seb << endl;
	

	return 0;
}