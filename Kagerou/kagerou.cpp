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

	// background texture
	if (!backgroundTexture.initialize(graphics, BACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	// background
	if (!background.initialize(graphics, 0, 0, 0, &backgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));
	
	// ship texture
	if (!shipTexture.initialize(graphics, SHIP_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship texture"));

	// ship
	if (!ship.initialize(graphics, SHIP_WIDTH, SHIP_HEIGHT, SHIP_COLS, &shipTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship"));
	ship.setX(GAME_WIDTH / 4);                    // start above and left of planet
	ship.setY(GAME_HEIGHT / 4);
	ship.setFrames(SHIP_START_FRAME, SHIP_END_FRAME);   // animation frames
	ship.setCurrentFrame(SHIP_START_FRAME);     // starting frame
	ship.setFrameDelay(SHIP_ANIMATION_DELAY);
    
	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Kagerou::update()
{
	ship.update(frameTime);
}

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
	ship.draw();
	
	graphics->spriteEnd();          //end drawing sprites

}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Kagerou::releaseAll()
{
	backgroundTexture.onLostDevice();
	shipTexture.onLostDevice();

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
	shipTexture.onResetDevice();

    Game::resetAll();
    return;
}
