#pragma once
#include "Vec2.h"

#include <memory>

class Camera
{
public:
	Camera();
	Camera(float x, float y, float a = 0, float s = 1);
	Camera(Vec2<float> pos, float a = 0, float s = 1);

	Vec2<float> position;
	float angle, scale;
};

using CameraPtr = std::shared_ptr<Camera>;