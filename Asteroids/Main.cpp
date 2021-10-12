#pragma warning(push)
#pragma warning(disable : 26812)
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#pragma warning(pop)
#include <stdio.h>
#include <string>
#include <cmath>
#include <sstream>
#include "LTimer.h"
#include "Starship.h"
#include "Space.h"

const int ASTEROIDS_COUNT = 5;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//Globally used font
TTF_Font* gFont = NULL;

//Scene renderer
LTexture gFPSTextTexture;
SDL_Renderer* gRenderer = NULL;


bool init(int* windowWidth, int* windowHeight)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create game windows, with default position
		//gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			0, 0, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
		SDL_GetWindowSize(gWindow, windowWidth, windowHeight);
		
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window, so rendering is synchronized with the refresh rate
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont("Resources/lazy.ttf", 14);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	return success;
}

void close()
{
	gFPSTextTexture.free();
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	int windowWidth = 0;
	int windowHeight = 0;

	//Start up SDL and create window
	if (!init(&windowWidth, &windowHeight))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			// Control weather bullet is shot after pressing the space bar
			bool bulletShot = false;

			//Event handler
			SDL_Event e;

			// Set white color for text
			SDL_Color textColor = { 255, 255, 255, 255 };

			// Create starship and space
			Space space(ASTEROIDS_COUNT, gRenderer, windowWidth, windowHeight);

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				const Uint8* kb = SDL_GetKeyboardState(NULL);

				if (kb[SDL_SCANCODE_ESCAPE] > 0)
				{
					quit = true;
				}

				// In memory text stream
				std::stringstream pointsText;

				// Rotate starship, left (-1) o right (+1) 
				// (kb[KEY] equals 1 if KEY is pressed
				space.getStarship()->rotate(kb[SDL_SCANCODE_RIGHT] - kb[SDL_SCANCODE_LEFT]);

				// If UP pressed, thrust
				if (kb[SDL_SCANCODE_UP] > 0)
				{
					space.getStarship()->thrust();
				}
				else
				{
					// Stop thrusting to change the texture to the normal spaceship
					space.getStarship()->stopThrust();
				}

				// We control bulletShot so only one bullet is shot we keep the key pressed 
				// for several frames
				if (kb[SDL_SCANCODE_SPACE] > 0 && !bulletShot)
				{
					space.addBullet(space.getStarship()->shoot());
					bulletShot = true;
				}
				else if (kb[SDL_SCANCODE_SPACE] == 0 && bulletShot)
				{
					bulletShot = false;
				}

				//Clear screen with black color
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
				SDL_RenderClear(gRenderer);
				// Back to drawing with white
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			

				// Calcualte movements for all the objects
				space.updateSpace();
				// Render everything
				space.render();

				pointsText << "Points: " << space.getPoints();

				//Render text
				if (!gFPSTextTexture.loadFromRenderedText(pointsText.str().c_str(), textColor, gRenderer, gFont))
				{
					printf("Unable to render Points texture!\n");
				}
				gFPSTextTexture.render(100, 50, gRenderer);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}