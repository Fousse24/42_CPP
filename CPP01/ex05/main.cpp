/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/20 18:57:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string>
#include	<iostream>
#include	"Karen.hpp"

int	main(int argc, char **argv)
{
	std::string	level;
	Karen		karen;

	if (argc != 2)
	{
		std::cout << "Error: requires 1 argument. Possible values : DEBUG INFO WARNING ERROR" << std::endl;
		return (EXIT_FAILURE);
	}
	level.assign(argv[1]);
	karen.complain(level);
	return (0);
}