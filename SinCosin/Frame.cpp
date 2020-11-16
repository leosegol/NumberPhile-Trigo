#include"Line.h"
#include"Circle.h"
#include"Frame.h"
#include<SDL.h>
#include<iostream>
#include<thread>

constexpr auto angle = 1;

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
		if (j == 360 / angle)
			j = 0;
		// going over the events that occured on the SDL window
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) // check if the window was closed
				return;

			else if (event.type == SDL_KEYDOWN) // checks if a button was pressed while focused on the SDL window
			{
				length = last_length;
				length++; // if a button was presed i increment the number of points that revolve 
				last_length = length;
				if (!(length % 2)) // when the number of points is even, half of the points perfectly overlap
					length *= 2; // so i double the number of points to avoid that
				for (int i = 0; i < length; i++)
					lines[i] = Line(360 / length, i);
			}
		} // end of checking events

		//clear the window
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);


		//changing the point of the followed point across the circle
		c.SetDegrree(angle * j);
		DataFrame(c, length, lines, points);

		//showing th circle
		/*
		SDL_SetRenderDrawColor(render, 0, 0, 255, 255); 
		SDL_Rect rect = { 500 + c.x, 350 + c.y, 10, 10 };
		SDL_RenderDrawRect(render, &rect);
		*/

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
	//create the circle and set it radius
	Circle c = Circle(200);

	//number of points to start
	int length = 1;
	//init the number of lines and points with max size (100)
	Line* lines = (Line*)malloc(100 * sizeof(Line));
	Point* points = (Point*)malloc(100 * sizeof(Point));

	//init the default x axis
	lines[0] = Line(360, 0);

	//init SDL 
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* w = SDL_CreateWindow("SinProject", 100, 100, 1000, 700, SDL_WINDOW_SHOWN);
	SDL_Renderer* render = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Start the main Loop
	renderLoop (render, points, lines, c, length);

	//free the heap
	free(points);
	free(lines);

	return 1;
}