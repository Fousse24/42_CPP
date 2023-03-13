/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:39:35 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::string;

class PresidentialPardonForm : public Form
{
private:

public:
	PresidentialPardonForm();
	PresidentialPardonForm( string target );
	PresidentialPardonForm( PresidentialPardonForm const &obj );
	~PresidentialPardonForm();

	PresidentialPardonForm &	operator=( PresidentialPardonForm const &obj );

	virtual void	execute( Bureaucrat const & executor) const;

};

std::ostream	&operator << ( std::ostream & o, PresidentialPardonForm const & obj );

#endif