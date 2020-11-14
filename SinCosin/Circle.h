#pragma once

class Circle
{
public:
	float x;
	float y;
	float r;

private:
	float degree;
	float sinP;
	float cosP;

public:
	Circle(float r);
	void SetDegrree(float degree);
};
