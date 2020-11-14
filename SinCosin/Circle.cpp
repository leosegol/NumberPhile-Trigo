#include<iostream>
#include<math.h>
#include"Circle.h"
// x^2 + y^2 = r^2

Circle::Circle(float r) :r(r), x(0), y(0){}

float Circle::SetX(float x)
{
	this->x = x;
	this->y = sqrt(pow(r, 2) - pow(x, 2));
	return y;
}

float Circle