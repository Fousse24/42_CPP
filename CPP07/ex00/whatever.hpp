/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:40:20 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/25 15:29:01 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WHATEVER_HPP
#define	WHATEVER_HPP

template< typename T >
void	swap( T & x, T & y )
{
	T	temp;
	temp = x;
	x = y;
	y = temp;
}

template< typename T >
T const &	min( T const &x, T const &y )
{
	return ( x < y ? x : y );
}

template< typename T >
T const &	max( T const &x, T const &y )
{
	return ( x > y ? x : y );
}



#endif