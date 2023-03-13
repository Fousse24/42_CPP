/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:26:50 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/25 16:31:24 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

/* IsPointInTri() - 
 * Used by IsPointInQuad(). Function takes the point and the triangle's 
 * vertices. It finds the area of the passed triangle (v1 v2 v3), and then the
 * areas of the three triangles (pt v2 v3), (pt v1 v3), and (pt v1 v2). If the
 * sum of these three is greater than the first, then the point is outside of
 * the triangle.
 */

Fixed	fixedAbs(Fixed f)
{
	if(f < 0)
		return (f * -1);
	else
		return (f);
}

Fixed	triArea(Point const & p1, Point const & p2, Point const & p3)
{
  Fixed	delta1(0.0f);
  Fixed	delta2(0.0f);
  
  delta1 = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY());
  delta2 = (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
  return ((delta1 - delta2) / 2.0f);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea = triArea(a, b, c);
	Fixed	area1 = triArea(point, a, b); 
	Fixed	area2 = triArea(point, b, c);
	Fixed	area3 = triArea(point, c, a);

	if (area1 < 0 && area2 < 0 && area3 < 0)
		return (true);
	else if (area1 > 0 && area2 > 0 && area3 > 0)
		return (true);
	return (false);
}

