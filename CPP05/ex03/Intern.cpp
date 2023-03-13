/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:47:45 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 16:29:41 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

using std::string;

Intern::Intern()
{
	_initForms();
}

Intern::Intern( Intern const & )
{
	_initForms();
}

Intern::~Intern()
{
	_initForms();
}

Intern &	Intern::operator=( Intern const & )
{
	return *this;
}

void	Intern::_initForms( void )
{
	_forms[0] = "shrubbery creation";
	_forms[1] = "robotomy request";
	_forms[2] = "presidential pardon";
	_makers[0] = &Intern::_makeShrubberyCreation;
	_makers[1] = &Intern::_makeRobotomyRequest;
	_makers[2] = &Intern::_makePresidentialPardon;
}

Form *	Intern::makeForm( string name, string target )
{
	Form	*form = NULL;
	int	i = 0;

	while (i < _n_forms)
	{
		if (!_forms[i].compare(name))
		{
			form = ((*this).*_makers[i])(target);
			break;
		}
		i++;
	}

	std::cout << "\033[1;36m";
	if (form)
		std::cout << "Intern creates form " << name << std::endl; 
	else
		std::cout << "Intern don't know how to create form (or the universe has refused to grant the form its existence) " << name << std::endl;
	std::cout << "\033[0m";
	
	return form;
}

Form *	Intern::_makeShrubberyCreation( string target )
{
	return (new ShrubberyCreationForm(target));
}

Form *	Intern::_makeRobotomyRequest( string target )
{
	return (new RobotomyRequestForm(target));
}

Form *	Intern::_makePresidentialPardon( string target )
{
	return (new PresidentialPardonForm(target));
}

std::ostream &	operator<<( std::ostream & o, Intern const & )
{
	std::cout << "Interns are not cool enough to have a name or any information, buddy." << std::endl;
	return o;
}