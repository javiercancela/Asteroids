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
#include "LTexture.h"
#include "LTimer.h"
#include "Starship.h"


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

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

//Scene texture
LTexture gStarshipTexture;
LTexture gFPSTextTexture;

SDL_Renderer* gRenderer = NULL;


bool init()
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

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
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

	//Load arrow
	if (!gStarshipTexture.loadFromFile("Resources/starship.png", gRenderer))
	{
		printf("Failed to load arrow texture!\n");
		success = false;
	}

	//Open the font
	gFont = TTF_OpenFont("Resources/lazy.ttf", 28);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}


	return success;
}

void close()
{
	//Free loaded images
	gStarshipTexture.free();
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
	//Start up SDL and create window
	if (!init())
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

			//Event handler
			SDL_Event e;

			//Angle of rotation
			double degrees_rot = 0;

			// Set white color for text
			SDL_Color textColor = { 255, 255, 255, 255 };

			// The frames per second timer
			LTimer fpsTimer;

			// In memory text stream
			std::stringstream timeText;

			// Start counting frames per second
			int countedFrames = 0;
			fpsTimer.start();

			// Create starship
			Starship starship;

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

				// Rotate starship
				degrees_rot = (2 * -kb[SDL_SCANCODE_LEFT]) + (2 * kb[SDL_SCANCODE_RIGHT]);
				starship.rotate(degrees_rot);

				// If UP pressed, thrust
				if (kb[SDL_SCANCODE_UP] > 0)
				{
					starship.thrust();
				}

				// Calculate and correct fps
				float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
				if (avgFPS > 2000000)
				{
					avgFPS = 0;
				}

				// Set text
				timeText.str("");
				timeText << "Average FPS: " << avgFPS;



				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render starship
				starship.calculatePosition();
				Uint32 starshipPosX = (SCREEN_WIDTH - gStarshipTexture.getWidth()) / 2 + starship.getXPos();
				if (starshipPosX > SCREEN_WIDTH)
				{
					starshipPosX = 0;
				}
				Uint32 starshipPosY = (SCREEN_HEIGHT - gStarshipTexture.getHeight()) / 2 - starship.getYPos();
				if (starshipPosY > SCREEN_WIDTH)
				{
					starshipPosX = 0;
				}
				//gStarshipTexture.render(starshipPosX, starshipPosY, gRenderer, NULL, starship.getStarshipDirection(), NULL, SDL_FLIP_NONE);
				gStarshipTexture.render(SCREEN_WIDTH-20, SCREEN_HEIGHT-20, gRenderer, NULL, starship.getStarshipDirection(), NULL, SDL_FLIP_NONE);

				//Render text
				if (!gFPSTextTexture.loadFromRenderedText(starship.getDebugText().str().c_str(), textColor, gRenderer, gFont))
				//if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor, gRenderer, gFont))
				{
					printf("Unable to render FPS texture!\n");
				}
				gFPSTextTexture.render(100, 50, gRenderer);
				//Update screen
				SDL_RenderPresent(gRenderer);
				++countedFrames;
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}