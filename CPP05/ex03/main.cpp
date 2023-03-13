/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/16 17:25:53 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>
#include	"Bureaucrat.hpp"
#include	"Form.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"
#include	"Intern.hpp"

#define TITLE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

using	std::cout;
using	std::endl;
using	std::string;

int	main()
{
	Bureaucrat	tok("Tok", 24);
	Bureaucrat	laube("Laube", 1);
	Bureaucrat	justine("Justine", 5);
	Bureaucrat	collet("Collet", 145);
	Bureaucrat	seb("Sébas", 150);
	Intern		gilles;
	
	cout << TITLE_COLOR << "TEST SETUP" << RESET_COLOR << endl;
	cout << "Bureaucrats" << endl;
	cout << tok << laube << seb << justine << collet << endl;

	Form *shrubEnthousiast;
	Form *robotomizer;
	Form *someRichDude;
	shrubEnthousiast = gilles.makeForm("shrubbery creation", "laube_Garden");
	robotomizer = gilles.makeForm("robotomy request", "Cthulu");
	someRichDude = gilles.makeForm("Some_Rich_Dude", "***licker");
	someRichDude = gilles.makeForm("presidential pardon", "***licker");
	cout << gilles << *shrubEnthousiast << *robotomizer << *someRichDude << endl;

	cout << endl << TITLE_COLOR << "FAILED SIGNING" << RESET_COLOR << endl;
	seb.signForm(*shrubEnthousiast);
	seb.signForm(*robotomizer);
	seb.signForm(*someRichDude);

	cout << endl << TITLE_COLOR << "FAILED EXECUTION (not signed)" << RESET_COLOR << endl;
	justine.executeForm(*shrubEnthousiast);
	justine.executeForm(*robotomizer);
	justine.executeForm(*someRichDude);

	cout << endl << TITLE_COLOR << "SIGNING" << RESET_COLOR << endl;
	collet.signForm(*shrubEnthousiast);
	laube.signForm(*robotomizer);
	tok.signForm(*someRichDude);

	cout << endl << TITLE_COLOR << "FAILED EXECUTION (grade)" << RESET_COLOR << endl;
	seb.executeForm(*shrubEnthousiast);
	collet.executeForm(*robotomizer);
	tok.executeForm(*someRichDude);

	cout << endl << TITLE_COLOR << "EXECUTION" << RESET_COLOR << endl;
	tok.executeForm(*shrubEnthousiast);
	laube.executeForm(*robotomizer);
	laube.executeForm(*robotomizer);
	laube.executeForm(*robotomizer);
	laube.executeForm(*robotomizer);
	justine.executeForm(*someRichDude);

	delete shrubEnthousiast;
	delete robotomizer;
	delete someRichDude;

	return 0;
}