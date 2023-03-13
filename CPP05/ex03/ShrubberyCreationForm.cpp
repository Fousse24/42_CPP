/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:49:18 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/18 15:49:38 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::string;

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation", "undefined", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( string target) : Form("shrubbery creation", target, 145, 137) 
{
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & obj ) : Form(obj.getName(), obj.getTarget(), 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & obj )
{
	setTarget(obj.getTarget());
	setSigned(obj.getSigned());
	return *this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	
	std::ofstream	ofile;

	canBeExecuted( executor ); // Throw exception if it can't be executed
	ofile.open((getTarget() + "_shrubbery"), std::fstream::out);
	if (ofile.fail())
	{
		cout << "File could not be opened to make a beautiful shrubbery";
		return;
	}
	this->writeTree(ofile);
	cout << "A fine shrubbery has been carefully arranged in " << getTarget() << "_shrubbery" << endl;
	ofile.close();
}
void	ShrubberyCreationForm::writeTree( std::ofstream & ofile ) const
{
	srand(time(0));
	float	width = rand() % 200 + 10;
	float	height = rand() % 200 + 20;
	float	trunk_ratio = 0.85;
	int		i;
	int		j;

	for (j = 0; j < height; j++)
	{
		for (i = 0; i < width; i++)
		{
			if (j > height * trunk_ratio)
			{
				if (i >= (0 + width / 3) && i <= (width - (width / 3)))
					ofile << "-";
				else
					ofile << " ";
			}
			else if (i >= 0 + ((width / 2.0f) * (1 - j / (height * trunk_ratio))) && i <= width - ((width / 2.0f) * (1 - j / (height * trunk_ratio))))
			{
				ofile << "|";
			}
			else
				ofile << " ";
		}
		ofile << "\n";
	} 
}

std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const & obj )
{
	cout << "\033[1;35m";
	cout << "ShrubberyCreationForm " << obj.getName() << endl;
	cout << "\033[0m";

	cout << "Target: " << obj.getTarget() << endl;

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