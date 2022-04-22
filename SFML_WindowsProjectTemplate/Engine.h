#pragma once

#include <vector>
#include <memory>

#include <SFML\Graphics.hpp>

#include "Vec2.h"
#include "Graphics.h"
#include "Controller.h"
#include "Camera.h"


using GraphicsPtr = std::shared_ptr<Graphics>;
using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;

/* Main class, contains renderer, event handlers and main logic */
class Engine
{
public:
	Engine();
	~Engine();

private:
	Vec2<int> window_size;

	/* minimal time in ms for main_loop() iteration */
	float tick_time;


	std::shared_ptr<Graphics> gr;
	std::shared_ptr<sf::RenderWindow> window;

	ControllerPtr control;


	/* ======== METHODS ======== */

	/* initialize SFML, create main window */
	void SFML_init();

	/* set properties, load configs */
	void config();

	/* reset all variables to initial values */
	void init();

	/* update */
	void tick();
	
	/* draw */
	void render();

	/* handle events */
	void events();

	void key_pressed(sf::Event::KeyEvent key);
	void mouse_pressed(sf::Event::MouseButtonEvent mouse);

	/* main loop iteration */
	void main_loop();

	/* after main window is closed */
	void close();
};



