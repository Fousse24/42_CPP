/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:47:47 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 16:29:27 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

using std::string;

class Intern
{
private:
	static int const	_n_forms = 3;
	string				_forms[3];
	Form *				(Intern::*_makers[3])( string );

	void	_initForms( void );
	Form *	_makeShrubberyCreation( string target );
	Form *	_makeRobotomyRequest( string target );
	Form *	_makePresidentialPardon( string target );
								 
public:
	Intern();
	Intern( Intern const &obj );
	~Intern();

	Intern &	operator=( Intern const &obj );

	Form *	makeForm( string name, string target );
};

std::ostream	&operator << ( std::ostream & o, Intern const & obj );

#endif