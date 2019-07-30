#include<cmath>
#include "Graphic.h"


double circle::get_area() const
{
	return radius * radius * PI;
}

double rectangle::get_area() const
{
	return width * length;
}

double sphere::get_volume() const
{
	return (4.0/3) * PI * radius * radius * radius;
}

double sphere::get_area() const
{
	return 4.0 * PI * radius * radius;
}

double cone::get_area() const
{
	return PI * radius * radius + PI * radius * busbar;
}

double cone::get_volume() const
{
	double height = sqrt(busbar * busbar - radius * radius);
	return PI * radius * radius * height / 3; 
}
