#include "Game.h"
#include <iostream>

// CONSTRUCTOR AND DESTRUCTOR

// 1. The default constructor must initialize the window with a string (window title) and an sf::Vector2u(800,600) for its size
//    Also the movement vector for the mushroom should be initalized to x=4.0f, y=4.0f.
//    Both the vector and the window must be set with a "member initializers list" (https://en.cppreference.com/w/cpp/language/constructor)
//    The body of the constructor must:
//      * Load the texture file (mushroom50-50.png) into the sf::Texture member variable using the loadFromFile function of the sf::Texture class.
//      * Set the sf::Texture variable as the texture of the sf::Sprite member (using the sf::Sprite::setTexture(sf::Texture) function).

Game::Game() : pause{false}, window{ "Game", sf::Vector2u(800,600) }, movement{ 4.0f,4.0f }
{
	mushroomTexture.loadFromFile("../GameLoop/mushroom50-50.png");
	sprite.setTexture(mushroomTexture);
}



// 2.  Define an empty default destructor.
Game::~Game()
{

}



// MEMBER FUNCTIONS:

// 3. For handling the input. This logic will not handle any input yet, so define an empty handling function.
void Game::handleInput()
{
	sf::Event event;
	if (event.key.code == sf::Keyboard::Space)
	{
		pause = !pause;
	}
}


// 4. For updating tha game state:
//	  a) Call the private function of this class that executes the logic (mushroom movement).
//    b) Call the update function of the window (the window does handle input in the update function. This is not really orthodox, 
//       but it will work for now).
void Game::update()
{
	if (!pause) 
	{
		moveMushroom();
		windowMember()->update();
	}
}


// 5. Function for rendering the game:
//    a) Our window object offers functionality for clearing the screen. Call the method that starts the draw on the window member first.
//    b) Draw the mushroom on screen, by calling the draw function in window that receives a reference to a sf::Drawable& reference.
//    c) Our window also offers functionality for displaying all that has been drawn since the last clear. Call the method that ends the draw on the window now.
void Game::render()
{
	if (!pause) 
	{
		windowMember()->beginDraw();
		windowMember()->draw(sprite);
		windowMember()->endDraw();
	}
	
}


// 6. Define the function that returns a pointer to the window member variable of this class.
Window* Game::windowMember()
{
	return &window;
}




// 7. Define the function for updating the movement of the mushroom.
//    The following is pseudocode (as I don't know how you named your member variables):
//
//    # Some initializations:
//    windowSize <- window.getWindowSize 
//    textureSize <- mushroomTexture.getSize
//    xRightLimit <- windowSize.width - textureSize.width
//    yBottomLimit <- windowSize.height - textureSize.height
//
//    # Check if we are bouncing off the right or left edges:
//    bouncesRight <- (mushroom.xPosition > xRightLimit AND mushroom.movement.x > 0)
//    bouncesLeft <- (mushroom.xPosition < 0 AND mushroom.movement.x < 0)
//    if bouncesRight OR bouncesLeft
//       { change sign of mushroom.movement.x }
//    
//    # Same for top or bottom edges:
//    bouncesBottom <- (mushroom.yPosition > yBottomLimit AND mushroom.movement.y > 0)
//    bouncesTop <- (mushroom.yPosition < 0 AND mushroom.movement.y < 0)
//    if bouncesBottom OR bouncesTop
//       { change sign of mushroom.movement.y }
//
//    # Set the position of the mushroom as its current position + movement.
//    mushroom.xPosition <- mushroom.xPosition + movement.x 
//    mushroom.yPosition <- mushroom.yPosition + movement.y

void Game::moveMushroom()
{
	sf::Vector2u windowSize = windowMember()->getWindowSize();
	sf::Vector2u textureSize = mushroomTexture.getSize();
	int xRightLimit = windowSize.x - textureSize.x;
	int yBottomLimit = windowSize.y - textureSize.y;

	// right or left
	bool bouncesRight = (sprite.getPosition().x > xRightLimit && movement.x() > 0);
	bool bouncesLeft = (sprite.getPosition().x < 0 && movement.x() < 0);

	if (bouncesRight || bouncesLeft)
	{
		movement.setX(-movement.x());
	}

	// top or bottom
	bool bouncesBottom = (sprite.getPosition().y > yBottomLimit && movement.y() > 0);
	bool bouncesTop = (sprite.getPosition().y < 0 && movement.y() < 0);

	if (bouncesBottom || bouncesTop)
	{
		movement.setY(-movement.y());
	}

	// set mushroom position
	sprite.setPosition((sprite.getPosition().x + movement.x()), (sprite.getPosition().y + movement.y()));

}


