#pragma once
#include "Vec2.h"
#include <random>

/* Additional mathematical functions */
struct ExtMath
{
public:
	static float get_random_float(float min, float max);
	static float get_random_double(double min, double max);
	static int get_random_int(int min, int max);

	static double to_radian(double a);
	static double to_degrees(double a);

	/* weighted average */
	static float waverage(float a1, float p1, float a2, float p2);

	static float hypot(float a1, float a2);
	static float hypot(float x1, float y1, float x2, float y2);
	static float hypot(Vec2<float> p1, Vec2<float> p2);

	/* sigmoid function */
	static double sigmoid(float x, float a);

	static int sign(double a);

	static constexpr double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
};


