#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "Vec2.h"
#include "Color.h"
#include "Camera.h"

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

/* Contains functions for drawing */
class Graphics
{
public:
	/* requires RenderWindow pointer, window's dimensions and Camera object pointer (optionally) */
	Graphics(std::shared_ptr<sf::RenderWindow> win, Vec2<int> ws);
	Graphics(std::shared_ptr<sf::RenderWindow> win, Vec2<int> ws, CameraPtr cam);

	/* draw a point with given coordinates */
	void draw_point(Vec2<float> pos);
	void draw_point(float x, float y);

	/* draw a point with given coordinates */
	void draw_circle(float x, float y, float radius);
	void draw_circle(Vec2<float> pos, float radius);

	/* draw broken line fith given verticies */
	void draw_broken_line(std::vector<Vec2<float>> t, Vec2<float> a, float s);

	/* draw straight line from one point to another */
	void draw_line(Vec2<float> v1, Vec2<float> v2);
	void draw_line(float x1, float y1, float x2, float y2);

	/* draw rectangle with given upper left angle coordinates, width and height */
	void draw_rect(float x, float y, float w, float h);
	void draw_rect(Vec2<float> pos, Vec2<float> size);

	/* draw texture with given upper left angle coordinates, width, height and rotation (rotation center is in the middle) */
	void draw_texture(sf::Texture& tex, float x, float y, float w, float h);
	void draw_texture(sf::Texture& tex, Vec2<float> pos, Vec2<float> size);
	void draw_texture(sf::Texture& tex, Vec2<float> pos, Vec2<float> size, float a);

	/* set color for drawing primitives */
	void set_fill_color(float r, float g, float b, float a);
	void set_fill_color(Color col);

	/* fill the screen with the same color */
	void fill();

	/* clear all */
	void clear();

	/* draw text with given coordinates, size and font */
	void fill_text(const std::string& text, float x, float y, float size, sf::Font& font);

	/* auxilary method */
	void apply_camera(CameraPtr cam);

	/* set camera */
	void set_camera(CameraPtr cam);

	/* set default camera parameters */
	void set_default_camera();

	/* update the window */
	void present();

private:
	std::shared_ptr<sf::RenderWindow> window;
	Color fill_color;

	CameraPtr camera;
	Vec2<int> window_size;
};

#endif