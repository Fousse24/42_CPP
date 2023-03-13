/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:05:17 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/28 16:59:42 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>

using std::string;

struct	isEqual
{
	int	const _n;

	isEqual(int const & n) : _n(n) {};
	int	operator()(int const & compare) const { return compare == _n; };
};

template < typename T >
bool	easyfind( T const & cont, int const & n )
{
	if (std::any_of(cont.begin(), cont.end(), isEqual(n)))
		return true;
	return false;
}


#endif
