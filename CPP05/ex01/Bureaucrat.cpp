/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:21:42 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/13 19:23:37 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
using std::string;

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

void	Bureaucrat::signForm( Form & form )
{
	
	if (form.getSigned())
		std::cout << "Form " << form.getName() << " has already been signed before." << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << "Bureaucrat " << getName() << " has signed Form " << form.getName() << " successfully!" << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cout << "Bureaucrat " << getName() << " couldn't sign Form " << form.getName() << " because " << e.what() << std::endl;
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
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return o;
}