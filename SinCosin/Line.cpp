#include"Line.h"
#include"Circle.h"
#include<iostream>
#include<math.h>

float rootFurmula(float a, float b, float c, float m, float r);

Line::Line(){}

Line::Line(float deg, int sir) : m(tan(deg*sir*Rad)){} //the slope of a line is tan(angle)
// where angle is the angle from the positive side of the x axis

float Line::Length(Circle &c)
{
	double len = abs(c.x * m + c.y);
	len = len / sqrt(pow(m, 2) + 1);
	this->len = len;
	return len;
}

void Line::FindC(Circle &c)
{
	float a = 1 + pow(m, 2), b = 2 * c.x -2*c.y*m, n = pow(c.x,2) + pow(c.y, 2) - pow(len, 2);
	this->x = -rootFurmula(a, b, n, m, c.r);
	this->y = -m * this->x;
}

float rootFurmula(float a, float b, float c, float m, float r)
{
	float x1, x2, discriminant, realPart, imaginaryPart;
	discriminant = b * b - 4 * a * c;

	if (discriminant > 0) {
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
		if (x1 * m < r)
			return x1;
		return x2;
	}

	x1 = -b / (2 * a);
	return x1;
}