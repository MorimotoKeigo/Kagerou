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
	if (input->isKeyDown(SHIP_RIGHT_KEY))            // if move right
	{
		ship.setX(ship.getX() + frameTime * SHIP_SPEED);
		if (ship.getX() > GAME_WIDTH)               // if off screen right
			ship.setX((float)-ship.getWidth());     // position off screen left
	}
	if (input->isKeyDown(SHIP_LEFT_KEY))             // if move left
	{
		ship.setX(ship.getX() - frameTime * SHIP_SPEED);
		if (ship.getX() < -ship.getWidth())         // if off screen left
			ship.setX((float)GAME_WIDTH);           // position off screen right
	}
	if (input->isKeyDown(SHIP_UP_KEY))               // if move up
	{
		ship.setY(ship.getY() - frameTime * SHIP_SPEED);
		if (ship.getY() < -ship.getHeight())        // if off screen top
			ship.setY((float)GAME_HEIGHT);          // position off screen bottom
	}
	if (input->isKeyDown(SHIP_DOWN_KEY))             // if move down
	{
		ship.setY(ship.getY() + frameTime * SHIP_SPEED);
		if (ship.getY() > GAME_HEIGHT)              // if off screen bottom
			ship.setY((float)-ship.getHeight());    // position off screen top
	}

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
