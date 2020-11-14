#include"Circle.h"
#include<iostream>

int main()
{
	Circle* c1 = new Circle(10);
	c1->SetDegrree(90);
	std::cout << c1->x << ", " << c1->y;

}