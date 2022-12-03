#pragma once
#include "GameObject.h"
#include "GLTexture.h"

class Ball: public GameObject
{
private:
	GLTexture ballTexture;
public: 
	Ball();
	virtual void draw();
	
};

