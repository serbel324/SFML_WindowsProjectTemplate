#include "Color.h"
#include "ExtMath.h"

#include <algorithm>

Color::Color(int r, int g, int b, int a)
{
	this->r = std::max(std::min(255, r), 0);
	this->g = std::max(std::min(255, g), 0);
	this->b = std::max(std::min(255, b), 0);
	this->a = std::max(std::min(255, a), 0);
}
Color::Color(int v)
{
	this->r = std::max(std::min(255, v), 0);
	this->g = std::max(std::min(255, v), 0);
	this->b = std::max(std::min(255, v), 0);
	this->a = 255;
}

Color::~Color()
{
}

Color Color::operator+(const Color& right) const
{
	return Color(r + right.r, g + right.g, b + right.b, a);
}

Color Color::operator+(const int right) const
{
	return Color(r + right, g + right, b + right, a);
}

Color Color::operator-(const Color& right) const
{
	return Color(r - right.r, g - right.g, b - right.b, a);
}

Color Color::operator-(const int right) const
{
	return Color(r - right, g - right, b - right, a);
}

Color Color::operator*(const float right) const
{
	return Color(r * right, g * right, b * right, a);
}

Color Color::get_random()
{
	return Color(
		ExtMath::get_random_int(0, 255), 
		ExtMath::get_random_int(0, 255), 
		ExtMath::get_random_int(0, 255)
	);
}
