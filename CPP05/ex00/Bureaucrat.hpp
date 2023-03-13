/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:21:43 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/13 18:22:55 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define BRT_MAX_GRADE 1
#define BRT_MIN_GRADE 150

using std::string;

class Bureaucrat
{
private:
	string const	_name;
	int				_grade;

	void	setGrade( int grade );

public:
	Bureaucrat();
	Bureaucrat( string name, int grade );
	Bureaucrat( Bureaucrat const &obj );
	~Bureaucrat();

	Bureaucrat &	operator=( Bureaucrat const &obj );

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

	string	getName( void ) const;
	int		getGrade( void ) const;

	void	promote( void );
	void	demote( void );
	bool	gradeTooHigh( int grade );
	bool	gradeTooLow( int grade );
};

std::ostream	&operator << ( std::ostream & o, Bureaucrat const & obj );

#endif