#include "Entity.h"

// Constructor AND Destructor
Entity::Entity(sf::Texture mushroomTexture) : movement{4.0f,4.0f}
{
	drawMushroom(mushroomTexture);
}


Entity::~Entity() 
{

}

void Entity::drawMushroom(sf::Texture mushroomTexture)
{
	mushroomTexture.loadFromFile("../GameLoop/mushroom50-50.png");
	sprite.setTexture(mushroomTexture);
}

// Mushroom movement
void Entity::moveMushroom() 
{
	windowSize = window.windowMember()->getWindowSize();
	textureSize = mushroomTexture.getSize();
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