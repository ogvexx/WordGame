#include "SDL.h"
#include "game.h"

GameData game;
	/** Main function for the game
	*Parm argv the number of arguments it has been started with
	*Parm args 
	*/

int main(int argv, char *args[])
{
	if(game.Setup() < 0)
	{
		return -1;
	}
	game.Run();
	game.Shutdown();
	return 0;

}