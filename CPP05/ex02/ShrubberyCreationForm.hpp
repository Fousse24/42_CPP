/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:39:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream> 
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::string;

class ShrubberyCreationForm : public Form
{
private:
	void	writeTree( std::ofstream & ofile ) const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( string target );
	ShrubberyCreationForm( ShrubberyCreationForm const &obj );
	~ShrubberyCreationForm();

	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const &obj );

	virtual void	execute( Bureaucrat const & executor) const;
};

std::ostream	&operator << ( std::ostream & o, ShrubberyCreationForm const & obj );

#endif