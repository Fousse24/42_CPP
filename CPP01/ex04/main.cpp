/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/06/13 19:02:50 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<fstream>

int	exitError(int code)
{
	std::cout << "Error: ";
	if (code == 1)
		std::cout << "file can't be opened";
	else if (code == 2)
		std::cout << "problem creating the new file";
	else if (code == 3)
		std::cout << "3 arguments are necessary; no more, no less.";
	std::cout << std::endl;
	return (code);
}

int	openFiles(char *path, std::ifstream &in, std::ofstream &out)
{	
	std::string	newName(path);

	newName.append(".replace");
	in.open(path);
	if (!in.is_open())
		return (exitError(1));
	out.open(newName);
	if (!out.is_open())
	{
		in.close();
		return (exitError(2));
	}
	return (0);
}

void	fillContent(std::ifstream &in, std::string &content)
{
	char	buffer;
	while (in)
	{
		in.get(buffer);
		if (in)
			content.push_back(buffer);
	}
}

void	replaceContent(std::string &base, std::string s1, std::string s2)
{
	int			i = 0;
	std::string	result;

	while ((size_t)i < base.length())
	{
		if (!base.compare(i, s1.length(), s1))
		{
			result.append(s2);
			i += s1.length();
		}
		else
		{
			result.push_back(base.at(i++));
		}
	}
	base = result;
}

int main(int argc, char **argv)
{
	std::ifstream 	filein;
	std::ofstream	fileout;
	std::string		s1;
	std::string		s2;
	std::string		content;
	int				exit_code;

	exit_code = 0;
	if (argc != 4)
		return (exitError(3));
	exit_code = openFiles(argv[1], filein, fileout);
	if (exit_code)
		return (EXIT_FAILURE);
	s1.assign(argv[2]);
	s2.assign(argv[3]);
	fillContent(filein, content); // Put the original file content and put it in a string
	replaceContent(content, s1, s2);
	fileout << content;
	filein.close();
	fileout.close();
	return (EXIT_SUCCESS);
	
}