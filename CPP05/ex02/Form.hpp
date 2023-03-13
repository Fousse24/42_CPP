/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:38:45 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

using std::string;
class Bureaucrat;

class Form
{
private:
	string const		_name;
	string				_target;
	bool				_signed;
	int const			_gradeSig; // minimum grade to sign
	int	const			_gradeExe; // minimum grade to execute
	static int const	_maxGrade = 1;
	static int const	_minGrade = 150;

protected:
	void	setSigned( bool isSigned );

public:
	Form();
	Form( string name, string target, int gradeSig, int gradeExe);
	Form( Form const &obj );
	virtual ~Form();

	Form &	operator=( Form const &obj );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	void	setTarget( string const & target );
	
	string	getName() const;
	string	getTarget() const;
	bool	getSigned() const;
	int		getGradeSignature() const;
	int		getGradeExecution() const;

	void			beSigned( Bureaucrat & brt );
	virtual void	execute( Bureaucrat const & executor ) const = 0;

	void	canBeExecuted( Bureaucrat const & executor ) const;
	void	validateGrade( int grade ) const;
	bool	gradeTooLow( int grade ) const;
	bool	gradeTooHigh( int grade ) const;
};

std::ostream	&operator << ( std::ostream & o, Form const & obj );

#endif