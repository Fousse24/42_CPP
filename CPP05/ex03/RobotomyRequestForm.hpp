/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:55 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/14 14:27:55 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <string>
#include <math.h>
#include "Form.hpp"

using std::string;

class RobotomyRequestForm : public Form
{
private:

public:
	RobotomyRequestForm();
	RobotomyRequestForm( string target );
	RobotomyRequestForm( RobotomyRequestForm const &obj );
	~RobotomyRequestForm();

	RobotomyRequestForm &	operator=( RobotomyRequestForm const &obj );

	virtual void	execute( Bureaucrat const & executor) const;

};

std::ostream	&operator << ( std::ostream & o, RobotomyRequestForm const & obj );

#endif