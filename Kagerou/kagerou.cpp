#include "kagerou.h"

//=============================================================================
// Constructor
//=============================================================================
Kagerou::Kagerou()
{}

//=============================================================================
// Destructor
//=============================================================================
Kagerou::~Kagerou()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Kagerou::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

	//background texture
	if (!backgroundTexture.initialize(graphics, BACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	// background
	if (!background.initialize(graphics, 0, 0, 0, &backgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Kagerou::update()
{}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Kagerou::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Kagerou::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void Kagerou::render()
{
	graphics->spriteBegin();		//begin drawing sprites

	background.draw();              //add the backgrond to the scene
	
	graphics->spriteEnd();          //end drawing sprites

}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Kagerou::releaseAll()
{
	backgroundTexture.onLostDevice();

    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Kagerou::resetAll()
{
	backgroundTexture.onResetDevice();

    Game::resetAll();
    return;
}
