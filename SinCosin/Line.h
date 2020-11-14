#pragma once
#include"Circle.h"
#include<iostream>
#include<math.h>

class Line
{
public:
	float m;
	float x;
	float y;
private:
	float len;
public:
	Line();
	Line(float deg, int sir);
	float Length(Circle &c);
	void FindC(Circle &c);
};