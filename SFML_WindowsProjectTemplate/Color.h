#pragma once
class Color
{
public:
	Color(int r, int g, int b, int a = 255);
	/* r, g, b are set to the same value v */
	Color(int v = 0);
	~Color();

	Color operator+ (const Color& right) const;
	Color operator- (const Color& right) const;
	Color operator+ (const int right) const;
	Color operator- (const int right) const;
	Color operator* (const float right) const;

	int r;
	int g;
	int b;
	int a;

	static Color get_random();
};