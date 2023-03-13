/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:21:42 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/15 17:29:18 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : _name("undefined")
{
	_grade = 150;
}

Bureaucrat::Bureaucrat(string name, int grade) : _name(name)
{
	_grade = 150;
	setGrade(grade);
}

Bureaucrat::Bureaucrat( Bureaucrat const &obj ) : _name(obj.getName())
{
	_grade = 150;
	setGrade(obj.getGrade());
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & obj )
{
	setGrade(obj.getGrade());
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Intended operation would set the grade above the highest possible."); 
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Intended operation would set the grade below the lowest possible."); 
}

void	Bureaucrat::promote()
{
	setGrade(getGrade() - 1);
}

void	Bureaucrat::demote()
{
	setGrade(getGrade() + 1);
}

void	Bureaucrat::executeForm( Form const & form )
{
	cout << "\033[1;34mBUREAUCRAT " << getName() << " ATTEMPTS TO EXECUTE FORM " << form.getName();
	cout << "\033[1;0m" << endl;
	try
	{
		form.execute(*this);
		cout << "Bureaucrat " << getName() << " has successfully executed Form " << form.getName() << "!" << endl;

	}
	catch(const std::exception& e)
	{
		cout << "Bureaucrat " << getName() << " couldn't execute Form " << form.getName() << ": " << e.what() << endl;
	}
}

void	Bureaucrat::signForm( Form & form )
{
	cout << "\033[1;35mBUREAUCRAT " << getName() << " ATTEMPTS TO SIGN FORM " << form.getName();
	cout << "\033[1;0m" << endl;
	if (form.getSigned())
		cout << "Form " << form.getName() << " has already been signed before." << endl;
	else
	{
		try
		{
			form.beSigned(*this);
			cout << "Bureaucrat " << getName() << " has signed Form " << form.getName() << " successfully!" << endl;

		}
		catch(const std::exception& e)
		{
			cout << "Bureaucrat " << getName() << " couldn't sign Form " << form.getName() << " because " << e.what() << endl;
		}
	}
}

bool	Bureaucrat::gradeTooHigh( int grade )
{
	if (grade < BRT_MAX_GRADE)
		return true;
	return false;
}

bool	Bureaucrat::gradeTooLow( int grade )
{
	if (grade > BRT_MIN_GRADE)
		return true;
	return false;
}

// This return an exception if the grade is invalid; you should catch it.
void	Bureaucrat::setGrade( int grade )
{
	if (gradeTooHigh(grade))
		throw Bureaucrat::GradeTooHighException();
	else if (gradeTooLow(grade))
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream &	operator << ( std::ostream & o, Bureaucrat const & obj )
{
	cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << endl;
	return o;
}