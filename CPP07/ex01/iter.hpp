/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:40:20 by sfournie          #+#    #+#             */
/*   Updated: 2022/03/25 15:49:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
#define	ITER_HPP

template< typename T >
void	iter( T * ptr, int size, void (*f)(T const &) )
{
	for (int i = 0; i < size; i++)
	{
		if (f != NULL)
			(*f)(ptr[i]);
	}
}

template< typename T >
void	some_function( T const & var)
{
	std::cout << var << std::endl;
}

#endif