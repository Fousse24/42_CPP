#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const	x;
	Fixed const	y;

public:

	Point() : x(0), y(0) {};
	Point( float const x, float const y ) : x(x), y(y) {};
	Point( Point const & src ) : x(src.x), y(src.y) {};
	~Point();

	Point	operator=( Point const & p );

	Fixed const	&getX( void ) const;
	Fixed const	&getY( void ) const;

};

std::ostream &	operator<<( std::ostream & o, Point const & i );
bool			operator == ( Point const & p1, Point const & p2 );

#endif