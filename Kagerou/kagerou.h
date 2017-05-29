#ifndef _SPACEWAR_H             // prevent multiple definitions if this 
#define _SPACEWAR_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"

//=============================================================================
// Create game class
//=============================================================================
class Kagerou : public Game
{
private:
	// game items
	TextureManager backgroundTexture;   // background texture
	TextureManager shipTexture;			// ship		  texture
	Image   background;                 // background image
	Image   ship;						// ship		  image

public:
    // Constructor
    Kagerou();

    // Destructor
    virtual ~Kagerou();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
};

#endif
