#include "Vec2.h"
#include "Graphics.h"
#include "ExtMath.h"

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

Graphics::Graphics(std::shared_ptr<sf::RenderWindow> win, Vec2<int> ws)
{
	window = win;
	fill_color = Color(0, 0, 0, 255);
	window_size = ws;
	set_default_camera();
}

Graphics::Graphics(std::shared_ptr<sf::RenderWindow> win, Vec2<int> ws, CameraPtr cam)
{
	window = win;
	fill_color = Color(0, 0, 0, 255);
	window_size = ws;
	camera = cam;
}

void Graphics::draw_point(float x, float y)
{
	draw_point(Vec2<float>(x, y));
}
void Graphics::draw_point(Vec2<float> pos)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(1, 1));
	rectangle.setPosition(pos.x, pos.y);

	rectangle.setFillColor(sf::Color(fill_color.r, fill_color.g, fill_color.b, fill_color.a));

	window->draw(rectangle);
}

void Graphics::draw_circle(float x, float y, float radius)
{
	draw_circle(Vec2<float>(x, y), radius);
}
void Graphics::draw_circle(Vec2<float> pos, float radius)
{
	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPosition(pos.x - radius, pos.y - radius);

	circle.setFillColor(sf::Color(fill_color.r, fill_color.g, fill_color.b, fill_color.a));

	window->draw(circle);
}

void Graphics::draw_broken_line(std::vector<Vec2<float>> t, Vec2<float> a, float s)
{
	for (int i = 1; i < t.size(); i++)
	{
		draw_line(t[i - 1] * s + a, t[i] * s + a);
	}
}

void Graphics::draw_line(Vec2<float> v1, Vec2<float> v2)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(v1.x, v1.y), sf::Color(fill_color.r, fill_color.g, fill_color.b, fill_color.a)),
		sf::Vertex(sf::Vector2f(v2.x, v2.y), sf::Color(fill_color.r, fill_color.g, fill_color.b, fill_color.a))
	};

	window->draw(line, 2, sf::Lines);
}

void Graphics::draw_line(float x1, float y1, float x2, float y2)
{
	draw_line(Vec2<float>(x1, y1), Vec2<float>(x2, y2));
}


void Graphics::draw_rect(float x, float y, float w, float h)
{
	draw_rect(Vec2<float>(x, y), Vec2<float>(w, h));
}

void Graphics::draw_rect(Vec2<float> pos, Vec2<float> size)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(size.x, size.y));
	rectangle.setPosition(pos.x, pos.y);

	rectangle.setFillColor(sf::Color(fill_color.r, fill_color.g, fill_color.b, fill_color.a));

	window->draw(rectangle);
}

void Graphics::draw_texture(sf::Texture& tex, float x, float y, float w, float h)
{
	draw_texture(tex, Vec2<float>(x, y), Vec2<float>(w, h));
}

void Graphics::draw_texture(sf::Texture& tex, Vec2<float> pos, Vec2<float> size)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);

	sf::Vector2u s = tex.getSize();

	sprite.setPosition(pos.x - size.x / 2, pos.y - size.y / 2);
	sprite.setScale(size.x / s.x, size.y / s.y);
	window->draw(sprite);
}

void Graphics::draw_texture(sf::Texture& tex, Vec2<float> pos, Vec2<float> size, float a)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);

	sf::Vector2u s = tex.getSize();

	sprite.setPosition(pos.x - size.x / 2, pos.y - size.y / 2);
	sprite.setScale(size.x / s.x, size.y / s.y);

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setRotation(ExtMath::to_degrees(a));

	window->draw(sprite);
}

void Graphics::present()
{
	window->display();
}

void Graphics::set_fill_color(float r, float g, float b, float a)
{
	fill_color.r = r;
	fill_color.g = g;
	fill_color.a = b;
	fill_color.a = a;
}

void Graphics::set_fill_color(Color col)
{
	fill_color = col;
}

void Graphics::fill()
{
	CameraPtr c = std::make_shared<Camera>();

	apply_camera(c);
	draw_rect(0, 0, window->getSize().x, window->getSize().y);
	apply_camera(camera);
}

void Graphics::clear()
{
	window->clear();
}

void Graphics::fill_text(const std::string& text, float x, float y, float size, sf::Font& font)
{
	sf::Text t;

	t.setFont(font);
	t.setString(text);
	t.setPosition(x, y);
	t.setCharacterSize(size);
	t.setFillColor(sf::Color(fill_color.r, fill_color.g, fill_color.b, fill_color.a));
	window->draw(t);
}

void Graphics::apply_camera(CameraPtr cam)
{
	sf::View view;
	Vec2<float> p = cam->position - window_size / 2;
	Vec2<float> s = window_size * cam->scale;

	view.reset(sf::FloatRect(p.x, p.y, s.x, s.y));
	view.rotate(cam->angle);
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

	window->setView(view);
}

void Graphics::set_camera(CameraPtr cam)
{
	camera = cam;
}

void Graphics::set_default_camera()
{
	camera = std::make_shared<Camera>();
}
