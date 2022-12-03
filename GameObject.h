#pragma once
#include "Vector3f.h"
class GameObject
{
	public:
		Vector3f position;
		virtual void draw() = 0;
};

