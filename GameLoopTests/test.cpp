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
	EXPECT_FALSE(w.isWindowDone());
	EXPECT_FALSE(w.isWindowFullscreen());

	EXPECT_TRUE(w.getTitle() == "Window");

	EXPECT_EQ(w.getWindowSize().x, 640);
	EXPECT_EQ(w.getWindowSize().y, 480);
}

TEST(Window, Init1)
{
	Window w("My Window", sf::Vector2u(1280, 1024));
	EXPECT_FALSE(w.isWindowDone());
	EXPECT_FALSE(w.isWindowFullscreen());
	EXPECT_TRUE(w.getTitle() == "My Window");
	EXPECT_EQ(w.getWindowSize().x, 1280);
	EXPECT_EQ(w.getWindowSize().y, 1024);
}

TEST(Window, Init2)
{
	Window w("Destroy Window", sf::Vector2u(1280, 1024));
	w.destroy();
	EXPECT_FALSE(w.isWindowDone());
	EXPECT_FALSE(w.isWindowFullscreen());
	EXPECT_TRUE(w.getTitle() == "Destroy Window");
	EXPECT_EQ(w.getWindowSize().x, 1280);
	EXPECT_EQ(w.getWindowSize().y, 1024);
}

//TEST(Window, Init3) 
//{
//	Window w("Redraw", sf::Vector2u(1280, 1024));
//	EXPECT_FALSE(w.isWindowFullscreen());
//	w.toggleFullscreen();
//	EXPECT_TRUE(w.isWindowFullscreen());
//	w.toggleFullscreen();
//	EXPECT_FALSE(w.isWindowFullscreen());
//}

