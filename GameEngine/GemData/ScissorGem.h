#ifndef SCISSORGEM_H
#define SCISSORGEM_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "../../Utilities/util.h"
#include "GemShape.h"
#include <iostream>

class ScissorGem : public GemShape
{
    public:
        ScissorGem()
        {
            //Default Constructor
        }
        void drawGem(int x, int y)
        {
            DrawRoundRect(x+5, y, 30, 40, colors[RED], 15);
        }
};

#endif