#include"Line.h"
#include"Circle.h"
#include"Frame.h"
#include<iostream>

constexpr auto length = 3;

Point* DataFrame(Circle& c, int num, Line* lines)
{
	Point points[length];
	for (int i = 0; i < num; i++)
	{
		lines[i].Length(c);
		lines[i].FindC(c);
		points[i].x = lines[i].x;
		points[i].y = lines[i].y;
	}
	return points;
}

int main()
{
	Circle c = Circle(10);
	Line lines[length];
	std::cout << sizeof lines / sizeof(Line) << std::endl;
	for (int i = 0; i < sizeof lines/ sizeof(Line); i++)
		lines[i] = Line(360 / sizeof lines, i);
	Point* points;
		c.SetDegrree(0);
		std::cout << c.x << ", " << c.y << std::endl;
		points = DataFrame(c, sizeof lines/ sizeof(Line), lines);
		// we need to draw points
			for (int i = 0; i < sizeof lines / sizeof(Line); i++)
			{
				std::cout << points[i].x << ", " << points[i].y << std::endl;
			}
	
}