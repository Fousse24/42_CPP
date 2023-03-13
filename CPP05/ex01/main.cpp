/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:38:15 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"Bureaucrat.hpp"
#include	"Form.hpp"

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
	cout << "Bureaucrats" << endl;
	cout << tok << laube << seb << endl;	

	Form tig("TIG", 1, 150);
	Form facture("Facture", 15, 10);
	cout << tig << facture << endl;

	cout << endl << TITLE_COLOR << "CONSTRUCTION OF INVALID FORMS" << RESET_COLOR << endl;
	cout << "Form Invalid_Low, unsigned, Grade grade 0+ to sign, Grade 10+ to execute" << endl;
	cout << "Form Invalid_High, unsigned, Grade 1+ to sign, Grade 151+ to execute" << endl;
	try	{ Form inv1("Invalid_Low", 0, 10); }
	catch (std::exception & e)
	{
		cout << "Exception during creation of Invalid_Low: " << e.what() << endl;
	}

	try	{ Form inv2("Invalid_High", 1, 151); }
	catch (std::exception & e)
	{
		cout << "Exception during creation of Invalid_High: " << e.what() << endl;
	}
	
	cout << endl << TITLE_COLOR << "SIGNING" << RESET_COLOR << endl;

	tok.signForm(tig);
	tok.signForm(facture);
	tok.signForm(facture);
	laube.signForm(tig);	

	return 0;
}