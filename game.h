/**
	* The game's driver class
*/
#ifndef __GAME_H_
#define __GAME_H_

class GameData
{
	int mGameState; /**< The state of the game */
	bool mChanged; /**< Has the screen changed */
	bool mDone;	   /**< Has the game ended */
	SDL_Window *mWindow; /**< The window */
	SDL_Surface *mScreenSurface; /**<The art */
	SDL_Surface *mimageSurface; /**< The surface for the art */
	//Private methods
	int Input();
	int Update();
	int Draw();
	
public:
	//Constructors and destructors
	//Public methods
	int Run();
	int Setup();
	int Shutdown();
};

extern GameData game;

#endif //__GAME_H_