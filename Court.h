#pragma once
#include "GameObject.h"
#include "GLTexture.h"
class Court :
    public GameObject
{
private:
    float width = 80;
    float height = 120;
    float thickness = 0.1f;
    float lineThickness = 0.5f;
public:
    Court();
    virtual void draw();
};

