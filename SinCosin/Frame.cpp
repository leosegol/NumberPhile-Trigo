#include"Line.h"
#include"Circle.h"
#include"Frame.h"
#include<SDL.h>
#include<iostream>
#include<thread>

//constexpr auto length = 10;

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

void renderLoop(SDL_Renderer* render, Point* points, Line* lines, Circle &c, int length)
{
	SDL_Event event;
	int last_length = length;
	for (int j = 0;; j++)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				length = last_length;
				length++;
				last_length = length;
				if (!(length % 2))
					length *= 2;
				for (int i = 0; i < length; i++)
					lines[i] = Line(360 / length, i);
				std::cout << length << std::endl;
			}
		}
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);

		SDL_SetRenderDrawColor(render, 255, 255, 0, 255);

		c.SetDegrree(1 * j);
		DataFrame(c, length, lines, points);

		SDL_Rect rect = { 500 + c.x, 350 + c.y, 10, 10 };
		SDL_RenderDrawRect(render, &rect);

		// we need to draw points
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		for (int i = 0; i < length; i++)
		{
			//std::cout << points[i].x << ", " << points[i].y << std::endl;
			SDL_Rect rect = { 500 + points[i].x, 350 + points[i].y, 10, 10 };
			SDL_RenderDrawRect(render, &rect);
		}
		SDL_RenderPresent(render);
	}

}

int main(int argc, char** argv) 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* w = SDL_CreateWindow("SinProject", 100, 100, 1000, 700, SDL_WINDOW_SHOWN);
	SDL_Renderer* render = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Circle c = Circle(200);
	int length = 1;
	Line* lines = (Line*)malloc(100 * sizeof(Line));
	for (int i = 0; i < length; i++)
		lines[i] = Line(360 / length, i);
	Point* points = (Point*)malloc(100 * sizeof(Point));
	renderLoop (render, points, lines, c, length);
	free(points);
	free(lines);
	return 1;
}