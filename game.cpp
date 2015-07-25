#include <SDL.h>
#include <stdio.h>
#include "game.h"

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

bool mDone = false;


SDL_Window *window=NULL;
SDL_Surface *screenSurface=NULL;
SDL_Surface *imageSurface=NULL;

int GameData::Setup()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)<0)
	{
		printf("SDL could not initiliaze! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	if ((window = SDL_CreateWindow("Hello World", 0,100,1280,720,0)) == NULL)
	{
		printf("SDL could not initiliaze! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	if ((screenSurface = SDL_GetWindowSurface(window)) == NULL)
	{
		printf("SDL could not initiliaze! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	if ((imageSurface = SDL_LoadBMP("Lego.bmp")) == NULL)
	{
		printf("SDL could not initiliaze! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	return 0;
}

int GameData::Draw()
{ 
	SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface(window);
	SDL_Delay(10);
	return 0;
}

int GameData::Input()
{
	SDL_Event EventE;
	SDL_PollEvent(&EventE);
	if (EventE.type == SDL_QUIT)
	{
		mDone = true;
	}
	return 0;
}

int GameData::Shutdown()
{
	SDL_FreeSurface(screenSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

int GameData::Run()
{
	do 
	{
		Input();
		Draw();
	}
	while(!mDone);

	return 0;
}



