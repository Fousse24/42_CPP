/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:49:18 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:48:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::cout;
using std::endl;
using std::string;

Form::Form() : _name("undefined"), _gradeSig(_maxGrade), _gradeExe(_maxGrade)
{
	_signed = false;
	_target = "undefined";
}

Form::Form( string name, string target, int gradeSig, int gradeExe) : _name(name), _gradeSig(gradeSig), _gradeExe(gradeExe)
{
	_signed = false;
	_target = target;
	
	validateGrade(_gradeSig);
	validateGrade(_gradeExe);
}

Form::Form( Form const & obj ) : _name(obj.getName()), _gradeSig(obj._gradeSig), _gradeExe(obj._gradeExe)
{
	_signed = obj.getSigned();
	_target = obj.getTarget();
	
	validateGrade(_gradeSig);
	validateGrade(_gradeExe);
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

const char* Form::NotSignedException::what() const throw()
{
	return ("Attempted to execute an unsigned form.");
}

void	Form::beSigned( Bureaucrat & brt )
{
	if (brt.getGrade() <= getGradeSignature())
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

void	Form::setSigned( bool isSigned ) { _signed = isSigned; }
void	Form::setTarget( string const & target) { _target = target; }

string	Form::getName() const { return _name; }
string	Form::getTarget() const { return _target; }
bool	Form::getSigned() const { return _signed; }
int		Form::getGradeSignature() const { return _gradeSig; }
int		Form::getGradeExecution() const { return _gradeExe; }

void	Form::canBeExecuted( Bureaucrat const & executor ) const
{
	if (executor.getGrade() > getGradeExecution())
		throw Form::GradeTooLowException();
	if (!getSigned())
		throw Form::NotSignedException();
}
void	Form::validateGrade( int grade ) const
{
	if (gradeTooLow(grade))
	{
		throw Form::GradeTooLowException();
	}
	else if (gradeTooHigh(grade))
	{
		throw Form::GradeTooHighException();
	}
}

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

	cout << "Target: " << obj.getTarget() << endl;

	cout << "Signed: ";
	if (obj.getSigned())
		cout << "yes";
	else
		cout << "no";
	cout << endl;
	
	cout << "Grade needed to sign: " << obj.getGradeSignature() << endl;
	cout << "Grade needed to execute: " << obj.getGradeExecution() << endl;
	return o;
}