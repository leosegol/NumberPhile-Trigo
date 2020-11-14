#pragma once
constexpr float Rad = 3.14159265358979323846 / 180;

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
