#ifndef SPHEREGEM_H
#define SPHEREGEM_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "../../Utilities/util.h"
#include "GemShape.h"
#include <iostream>

class SphereGem : public GemShape
{
    public:
        SphereGem()
        {
            //Default Constructor
        }
        void drawGem(int x, int y)
        {
            DrawCircle(x+20, y+20, 20, colors[YELLOW]);   
        }
};

#endif