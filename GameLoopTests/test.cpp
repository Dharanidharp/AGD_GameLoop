#include "pch.h"
#include <SFML/Graphics.hpp>
#include "../GameLoop/Vector.h"
#include "../GameLoop/Window.h"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Vector, Init2) 
{
	Vector v1(1.0f, 2.0f);
	EXPECT_EQ(v1.x(), 1.0f);
	EXPECT_EQ(v1.y(), 2.0f);

}

TEST(Window, Init0)
{
	Window w;
	//sf::RenderWindow wr;
}