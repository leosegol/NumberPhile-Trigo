#include<iostream>
#include<math.h>
#include"Circle.h"
// x^2 + y^2 = r^2
// asin(x)*180/3.1415
Circle::Circle(float r) :r(r), degree(0){}

void Circle::SetDegrree(float deg)
{
	degree = deg * Rad;
	x = r * cos(degree);
	y = r * sin(degree);
}



