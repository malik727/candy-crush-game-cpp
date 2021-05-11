#ifndef TRIANGLEGEM_H
#define TRIANGLEGEM_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "../../Utilities/util.h"
#include "GemShape.h"
#include <iostream>

class TriangleGem : public GemShape
{
    public:
        TriangleGem()
        {
            //Default Constructor
        }
        void drawGem(int x, int y)
        {
            glBegin(GL_TRIANGLES);
            glColor3f(0.294, 0.000, 0.510);
            glVertex4i(x, y, 0, 1);
            glColor3f(0.729, 0.333, 0.827);
            glVertex4i(x+40, y, 0, 1);
            glColor3f(0.855, 0.439, 0.839);
            glVertex4i(x+20, y+40, 0, 1);
            glEnd();
        }
};

#endif