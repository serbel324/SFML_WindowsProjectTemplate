#include "Engine.h"

#include <fstream>
#include <cstdlib>
#include <ctime>

#include <chrono>

Engine::Engine()
{
	config();
	SFML_init();

	gr = std::make_shared<Graphics>(window, window_size);
	CameraPtr cam = std::make_shared<Camera>(window_size / 2, 0, 1); /* Camera with center in upper left angle */
	gr->apply_camera(cam);

	init();

	while (window->isOpen())
	{
		main_loop();
	}

	close();
}

Engine::~Engine()
{
}

void Engine::SFML_init()
{
	window = std::make_shared<sf::RenderWindow>(
		sf::VideoMode(window_size.x, window_size.y), 
		"Unnamed", 
		sf::Style::Close);
}

void Engine::config()
{
	/* default screen resolution is 800x800 */
	window_size = Vec2<int>(800, 800);
	tick_time = 10;
}

void Engine::init()
{
	control = std::make_shared<Controller>();
}

void Engine::tick()
{
}

void Engine::render()
{
	gr->set_fill_color(Color(20));
	gr->fill();

	/* ...  */

	gr->present();
}


void Engine::events()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			key_pressed(e.key);
			control->key_pressed(e.key);
			break;
		case sf::Event::KeyReleased:
			control->key_pressed(e.key);
			break;
		case sf::Event::MouseButtonPressed:
			control->mouse_pressed(e.mouseButton);
			break;
		case sf::Event::MouseButtonReleased:
			control->mouse_released(e.mouseButton);
			break;
		case sf::Event::MouseMoved:
			control->mouse_moved(e.mouseMove);
			break;
		}
	}
}

void Engine::key_pressed(sf::Event::KeyEvent key)
{
	if (key.code == sf::Keyboard::Escape) {
		window->close();
	}
}

void Engine::mouse_pressed(sf::Event::MouseButtonEvent mouse)
{
}

void Engine::main_loop()
{
	sf::Clock clock;

	events();
	tick();
	render();

	sf::Time t = clock.getElapsedTime();

	if (t.asMilliseconds() < tick_time)
	{
		sf::sleep(sf::milliseconds(tick_time - t.asMilliseconds()));
	}
}

void Engine::close()
{
}
