#pragma once

class Circle
{
public:
	const int func;
	float x;
	float y;
	float r;

private:
	float* funcs;
	float sin;
	float cos;

	Circle(float r);
	float SetX(float x);
	float Getsin();
	float Getcos();
};
