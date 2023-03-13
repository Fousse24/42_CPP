/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:45:27 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/28 14:10:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Point.hpp"
using std::cout;
using std::endl;

bool	bsp( Point const a, Point const b, Point const c, Point const point );

bool	is_inside( Point const a, Point const b, Point const c, Point const p )
{
	if (bsp(a, b, c, p))
	{
		cout << p << " is inside " << a << " " << b << " " << c << endl;
		return (true);
	}
	else
	{
		cout << p << " is outside " << a << " " << b << " " << c << endl;
		return (false);
	}
}

int main( void ) 
{
	Point	a(0.0f, 2.0f);
	Point	b(-2.0f, -2.0f);
	Point	c(2.0f, -2.0f);
	Point	d(c);
	Point	e;

	e = a;
	
	Fixed x;
	Fixed y = 2.2f;
	cout << "d (d(c))" << d << endl;
	cout << "e (e = a) " << e << endl;
	cout << "a " << a << endl;
	cout << "b " << b << endl;
	cout << "c " << c << endl;
	cout << endl;

	Point p(0.0f, 1.8f);
	int	drawn = 0;
	while (y > -2.2f)
	{
		x = -2.2f;
		while (x < 2.2f)
		{
			Point xy(x.toFloat(), y.toFloat());
			if (drawn == 0 && p.getX() <= x && p.getY() >= y)
			{
				drawn = 1;
				cout << "+";
			}
			else if (bsp(a, b, c, Point(x.toFloat(), y.toFloat())))
				cout << ".";
			else
				cout << " ";
			// x++;
			x = x + 0.05f;
		}
		cout << endl;
		// y--;
		y = y - 0.05f;
	}	

	is_inside(a, b, c, p);
	// is_inside(a, b, c, Point(-0.1f, -0.3f));
	// is_inside(a, b, c, a);
	// is_inside(a, b, c, b);
	// is_inside(a, b, c, c);
	// is_inside(a, b, c, Point(a.getX().toFloat() + 0.1f, a.getY().toFloat() - 0.2f));
	// is_inside(a, b, c, Point(4.1f, 49.0f));
	// is_inside(a, b, c, Point(2.0f, 2.0f));
	// is_inside(a, b, c, Point(0.0f, 7.0f));
	
	return 0;
}