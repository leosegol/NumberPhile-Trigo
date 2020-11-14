#include"Line.h"
#include"Circle.h"
#include"Frame.h"
#include<iostream>


Point* DataFrame(Circle& c, int num, Line* lines)
{
	Point points[30];
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
	Line lines[30];
	for (int i = 0; i < sizeof lines/ sizeof(Line); i++)
		lines[i] = Line(360 / sizeof lines, i);
	Point* points;
	int j = 0;
		c.SetDegrree(0.5 * j);
		std::cout << c.x << ", " << c.y << std::endl;
		points = DataFrame(c, sizeof lines/ sizeof(Line), lines);
		// we need to draw points
			for (int i = 0; i < sizeof lines; i++)
			{
				std::cout << points[i].x << ", " << points[i].y << std::endl;
			}
	
}