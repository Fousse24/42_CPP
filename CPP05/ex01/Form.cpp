/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:49:18 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:38:03 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::cout;
using std::endl;
using std::string;

Form::Form() : _name("undefined"), _gradeSig(_minGrade), _gradeExe(_minGrade)
{
	_signed = false;
}

Form::Form( string name, int gradeSig, int gradeExe) : _name(name), _gradeSig(gradeSig), _gradeExe(gradeExe)
{
	_signed = false;
	
	if (gradeTooHigh(_gradeSig) || gradeTooHigh(_gradeExe))
		throw Form::GradeTooHighException();
	else if (gradeTooLow(_gradeSig) || gradeTooLow(_gradeExe))
		throw Form::GradeTooLowException();
}

Form::Form( Form const & obj ) : _name(obj.getName()), _gradeSig(obj._gradeSig), _gradeExe(obj._gradeExe)
{
	_signed = obj.getSigned();
	
	if (gradeTooHigh(_gradeSig) || gradeTooHigh(_gradeExe))
		throw Form::GradeTooHighException();
	else if (gradeTooLow(_gradeSig) || gradeTooLow(_gradeExe))
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form &	Form::operator=( Form const & )
{
	return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Given grade is above the maximum.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Given grade is below the minimum.");
}

void	Form::beSigned( Bureaucrat & brt )
{
	if (brt.getGrade() <= getGradeSignature())
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

string	Form::getName() const { return _name; }
bool	Form::getSigned() const { return _signed; }
int		Form::getGradeSignature() const { return _gradeSig; }
int		Form::getGradeExecution() const { return _gradeExe; }

bool	Form::gradeTooHigh( int grade ) const
{
	if (grade < _maxGrade)
		return true;
	return false;
}

bool	Form::gradeTooLow( int grade ) const
{
	if (grade > _minGrade)
		return true;
	return false;
}

std::ostream &	operator<<( std::ostream & o, Form const & obj )
{
	cout << "\033[1;33m";
	cout << "Form " << obj.getName() << endl;
	cout << "\033[0m";

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