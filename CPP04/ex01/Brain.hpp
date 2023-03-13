/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:53 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/04 17:09:52 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

#define	B_COLOR	"\033[1;35m"
#define	B_RESET	"\033[m"

using	std::string;

class Brain
{
	private:
		string	ideas[100];
	public:
		Brain();
		Brain(Brain const & obj);
		~Brain();

		Brain	&operator=(Brain const & obj);

};

#endif