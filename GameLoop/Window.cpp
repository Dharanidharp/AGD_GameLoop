#include "Window.h"

Window::Window() : isDone(false), isFullscreen(false) // : <FILL THIS INITIALIZATION LIST with default values for isDone and isFullScreen>
{
	// Initialize the window calling the setup() method with a title and a size.
	// Pick a title of your choice. A recommended size is a sf::Vector2u(640, 480)
	setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& title, const sf::Vector2u& size) : isDone(false), isFullscreen(false) // : <FILL THIS INITIALIZATION LIST with default values for isDone and isFullScreen>
{
	// Redirect the call to the setup() function with the title and the size.
	setup(title, size);
}


Window::~Window()
{
	//This destructor needs to liberate the resources of the window when it's being destroyed. 
	// Simply call the destroy() method so it's delegated there.
	destroy();
}


void Window::setup(const std::string& title, const sf::Vector2u& size)
{
	// Give a value to the variables windowTitle, windowSize (from parameters), isFullscreen and isDone (default values).
	// Then, call the create() function that it will give a value to the window member.
	windowTitle = title;
	windowSize = size;
	isFullscreen = false;
	isDone = false;
	create();
}

void Window::create()
{
	// Create a variable "style" of a type deduced by "auto". Set its value to sf::Style::Fullscreen
	// if this object's isFullscreen is true, and to sf::Style::Default if isFullscreen is false.
	auto style{ sf::Style::Default };

	if (this->isFullscreen)
		style = sf::Style::Fullscreen;
	else
		style = sf::Style::Default;

	// Create an sf::VideoMode object passing two parameters to its constructor: windowSize.x and windowSize.y.
	//   -> bonus: do this using "direct brace initialization" 
	sf::VideoMode videoMode{ sf::VideoMode(windowSize.x, windowSize.y) };


	//Call the function create() in sf::RenderWindow window, passing as parameters in this order: video mode, window title and style.
	window.create(videoMode, windowTitle, style);

}

void Window::destroy()
{
	// Call the function close() on the window object. This will liberate the resources used by the sf::RenderWindow.
	window.close();
}

void Window::redraw()
{
	//Simple: two consecutive calls. First to destroy(), then to create().
	destroy();
	create();
}

void Window::beginDraw()
{
	//sf::RenderWindow has a function clear(), which clears the screen with a color. Call this function passing a black colour
	// (sf::Color::Black) as a parameter.
	window.clear(sf::Color::Black);

}

void Window::draw(sf::Drawable& drawable) {
	// sf::RenderWindow has a function "draw" that receives as parameter a sf::Drawable&. Simply redirect this call to the window method.
	window.draw(drawable);

}

void Window::endDraw()
{
	// It's time to display all that we've drawn since the last time we cleared the screen.
	// Simply call the display() function in the sf::RenderWindow window object.
	window.display();
}

void Window::toggleFullscreen()
{
	// For toggling the fullscreen status, you do two things:
	//  1. Change the value of the isFullscreen from false to true, and viceversa.
	//  2. Call redraw() in this class so a new window can be created after the current one is destroyed.
	isFullscreen = !isFullscreen;
	redraw();
}


void Window::update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			//This marks that the window has been closed. Set isDone to true.


		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			//This marks that the key F5 has been pressed. We're binding this to the toggle fullscreen function, so call it here.



		}

	}
}



