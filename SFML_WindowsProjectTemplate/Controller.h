#pragma once
#include "Vec2.h"

#include <SFML\Window.hpp>

#include <memory>

/* this class contains controller's state (keys pressed, mouse position, etc) and
    handles input events */

class Controller
{
public:
    bool w, a, s, d;
    bool lmb, rmb;
    bool space;
    Vec2<float> mouse_pos;

    Controller();
    void key_pressed(sf::Event::KeyEvent& e);
    void key_released(sf::Event::KeyEvent& e);
    void mouse_moved(sf::Event::MouseMoveEvent& e);
    void mouse_pressed(sf::Event::MouseButtonEvent& e);
    void mouse_released(sf::Event::MouseButtonEvent& e);
};

using ControllerPtr = std::shared_ptr<Controller>;
