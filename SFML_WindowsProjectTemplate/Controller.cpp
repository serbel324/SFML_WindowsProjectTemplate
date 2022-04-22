#include "Controller.h"

Controller::Controller() {
    w = a = s = d = false;
    lmb = rmb = false;
    mouse_pos.set(0, 0);
}

void Controller::key_pressed(sf::Event::KeyEvent& e)
{
    switch (e.code) {
    case sf::Keyboard::W:
        w = true;
        break;
    case sf::Keyboard::A:
        a = true;
        break;
    case sf::Keyboard::S:
        s = true;
        break;
    case sf::Keyboard::D:
        d = true;
        break;
    case sf::Keyboard::Space:
        space = true;
        break;
    }
}

void Controller::key_released(sf::Event::KeyEvent& e)
{
    switch (e.code) {
    case sf::Keyboard::W:
        w = false;
        break;
    case sf::Keyboard::A:
        a = false;
        break;
    case sf::Keyboard::S:
        s = false;
        break;
    case sf::Keyboard::D:
        d = false;
        break;
    case sf::Keyboard::Space:
        space = false;
        break;
    }
}

void Controller::mouse_moved(sf::Event::MouseMoveEvent& e)
{
    mouse_pos.set(e.x, e.y);
}

void Controller::mouse_pressed(sf::Event::MouseButtonEvent& e)
{
    switch (e.button) {
    case sf::Mouse::Left:
        lmb = true;
        break;
    case sf::Mouse::Right:
        rmb = true;
        break;
    }
}

void Controller::mouse_released(sf::Event::MouseButtonEvent& e)
{
    switch (e.button) {
    case sf::Mouse::Left:
        lmb = false;
        break;
    case sf::Mouse::Right:
        rmb = false;
        break;
    }
}