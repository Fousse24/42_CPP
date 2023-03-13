/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:49:18 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/15 14:54:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;
using std::string;

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", "undefined", 72, 45)
{
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm( string target) : Form("robotomy request", target, 72, 45) 
{
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & obj ) : Form(obj.getName(), obj.getTarget(), 72, 45)
{
	srand(time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & obj )
{
	srand(time(0));
	setTarget(obj.getTarget());
	setSigned(obj.getSigned());
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{	
	canBeExecuted( executor ); // Throw exception if it can't be executed

	cout << "Attempting to robotomize..." << endl;
	if (rand() % 2 == 1)
		cout << "\033[1;34mRobotomization successful\033[0m! Praise our robot overlords!" << endl;
	else
	{
		cout << "\033[1;31mRobotomization failed\033[0m... ";
		cout << "Please, do not sue us for any permanent brain destruction. Have a good day!" << endl;
	}
}

std::ostream &	operator<<( std::ostream & o, RobotomyRequestForm const & obj )
{
	cout << "\033[1;36m";
	cout << "RobotomyRequestForm " << obj.getName() << endl;
	cout << "\033[0m";

	cout << "Target: " << obj.getTarget() << endl;

	cout << "Signed : ";
	if (obj.getSigned())
		cout << "yes";
	else
		cout << "no";
	cout << endl;
	cout << "Grade needed to sign: " << obj.getGradeSignature() << endl;
	cout << "Grade needed to execute: " << obj.getGradeExecution() << endl;
	return o;
}