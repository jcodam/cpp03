#include "point.hpp"
#include <math.h>

/* A utility function to calculate area of triangle formed by (a),
	(b) and (c) */
Fixed area(point const &a, point const &b, point const &c)
{
	return ((a.getX()*(b.getY()-c.getY()) + b.getX()*(c.getY()-a.getY())+ c.getX()*(a.getY()-b.getY()))/Fixed(2));
}
  
/* A function to check whether point P(x, y) lies inside the triangle formed
	by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool bsp( point const a, point const b, point const c, point const point)
{
	/* Calculate area of triangle ABC */
	Fixed A = area (a, b, c);
	if (A == Fixed())
		return false;
	if (A < Fixed())
		A *= Fixed(-1);

	/* Calculate area of triangle PBC */ 
	Fixed A1 = area (point, b, c);
	if (A1 == Fixed())
		return false;
	if (A1 < Fixed())
		A1 *=Fixed(-1);
  
	/* Calculate area of triangle PAC */ 
	Fixed A2 = area (a, point, c);
	if (A2 == Fixed())
		return false;
	if (A2 < Fixed())
		A2 *= Fixed(-1);
  
	/* Calculate area of triangle PAB */  
	Fixed A3 = area (a, b, point);
	if (A3 == Fixed())
		return false;
	if (A3 < Fixed())
		A3 *= Fixed(-1);
	// std::cout << " " << A << " " << A1 << " " << A2 << " " << A3 << std::endl;
	/* Check if sum of A1, A2 and A3 is same as A */
	if (A == (A1 + A2 + A3))
		return true;
	return false;
}