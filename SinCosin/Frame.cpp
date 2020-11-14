#include"Line.h"
#include"Circle.h"
#include"Frame.h"
#include<SDL.h>
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
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* w = SDL_CreateWindow("SinProject", 0, 0, 1000, 700, SDL_WINDOW_SHOWN);
	SDL_Renderer* render = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Circle c = Circle(10);
	Line lines[length];
	std::cout << sizeof lines / sizeof(Line) << std::endl;
	for (int i = 0; i < sizeof lines/ sizeof(Line); i++)
		lines[i] = Line(360 / sizeof lines, i);
	Point* points;
	SDL_Event event;
	for(int j = 0;;j++)
	{ 
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				exit(1);
			}
		}
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);

		SDL_SetRenderDrawColor(render, 255, 255, 0, 255);

		c.SetDegrree(1*j);
		std::cout << c.x << ", " << c.y << std::endl;
		points = DataFrame(c, sizeof lines/ sizeof(Line), lines);
		// we need to draw points

		for (int i = 0; i < sizeof lines / sizeof(Line); i++)
		{
			//std::cout << points[i].x << ", " << points[i].y << std::endl;
			SDL_Rect rect = { points[i].x, points[i].y, points[i].x+10, points[i].y+10 };
		}
	
	}
	
}