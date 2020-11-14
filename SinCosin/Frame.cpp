#include"Line.h"
#include"Circle.h"
#include"Frame.h"
#include<SDL.h>
#include<iostream>

constexpr auto length = 30;

Point points[length];
void DataFrame(Circle& c, int num, Line* lines, Point* points)
{
	for (int i = 0; i < num; i++)
	{
		lines[i].Length(c);
		lines[i].FindC(c);
		points[i].x = lines[i].x;
		points[i].y = lines[i].y;
	}
}

int main(int argc, char** argv) 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* w = SDL_CreateWindow("SinProject", 100, 100, 1000, 700, SDL_WINDOW_SHOWN);
	SDL_Renderer* render = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Circle c = Circle(200);
	Line lines[length];
	std::cout << sizeof lines / sizeof(Line) << std::endl;
	for (int i = 0; i < sizeof lines/ sizeof(Line); i++)
		lines[i] = Line(360 / (sizeof lines/ sizeof(Line)), i);
	Point points[length] = { 0 };
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
		//std::cout << "blue " << c.x << ", " << c.y << std::endl;
		DataFrame(c, sizeof lines/ sizeof(Line), lines, points);

		SDL_Rect rect = { 500 + c.x, 350 + c.y, 10, 10 };
		SDL_RenderDrawRect(render, &rect);

		// we need to draw points
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		for (int i = 0; i < sizeof lines / sizeof(Line); i++)
		{
			//std::cout << points[i].x << ", " << points[i].y << std::endl;
			SDL_Rect rect = { 500 + points[i].x, 350 + points[i].y, 10, 10 };
			SDL_RenderDrawRect(render, &rect);
		}
		SDL_RenderPresent(render);
	}
	
}