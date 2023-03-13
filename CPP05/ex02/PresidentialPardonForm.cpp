/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:49:18 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:41:51 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;
using std::string;

PresidentialPardonForm::PresidentialPardonForm() : Form("presidential pardon", "undefined", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( string target) : Form("presidential pardon", target, 25, 5) 
{
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & obj ) : Form(obj.getName(), obj.getTarget(), 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & obj )
{
	setTarget(obj.getTarget());
	setSigned(obj.getSigned());
	return *this;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	canBeExecuted( executor );
	cout << getTarget() << " has been wrongfully pardoned by Zaphod Beeblebrox" << endl;
}

std::ostream &	operator<<( std::ostream & o, PresidentialPardonForm const & obj )
{
	cout << "\033[1;35m";
	cout << "PresidentialPardonForm " << obj.getName() << endl;
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