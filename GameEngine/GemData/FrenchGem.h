#ifndef FRENCHGEM_H
#define FRENCHGEM_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "../../Utilities/util.h"
#include "GemShape.h"
#include <iostream>

class FrenchGem : public GemShape
{
    public:
        FrenchGem()
        {
            //Default Constructor
        }
        void drawGem(int x, int y)
        {
            int mx = 40, my = 40;
            glBegin(GL_TRIANGLES);
                glColor3f(0.000, 0.749, 1.000);
                glVertex4f(x, y, 0, 1);
                glVertex4f(x + mx - 1, y, 0, 1);
                glVertex4f(x + mx - 1, y + my - 1, 0, 1);
                glVertex4f(x, y, 0, 1);
                glColor3f(0.392, 0.584, 0.929);
                glVertex4f(x + mx - 1, y + my - 1, 0, 1);
                glColor3f(0.255, 0.412, 0.882);
                glVertex4f(x, y + my - 1, 0, 1);
            glEnd();
        }
};

#endif