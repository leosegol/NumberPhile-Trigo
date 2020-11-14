#include"Line.h"
#include"Circle.h"
#include<iostream>
#include<math.h>

Line::Line()
{
}

Line::Line(float deg, int sir) : m(tan(deg*sir*Rad)){}

float Line::Length(Circle &c)
{
	float len = abs(c.x * m + c.x);
	len = len / sqrt(pow(m, 2) + 1);
	this->len = len;
	return len;
}

void Line::FindC(Circle &c)
{
	float a = asin(c.r / len);
	float d = c.r / cos(a);
	this->x = sqrt(pow(d, 2) / (1 + pow(m, 2)));
	this->y = m * this->x;
}
