#ifndef BAGUETTEGEM_H
#define BAGUETTEGEM_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "../../Utilities/util.h"
#include "GemShape.h"
#include <iostream>

class BaguetteGem : public GemShape
{
    public:
        BaguetteGem()
        {
            //Default Constructor
        }
        void drawGem(int sx, int sy)
        {
            glColor3fv(colors[SALMON]); 
            sx += 5;
            int mx = 30, my = 40;
            glBegin(GL_TRIANGLES);
                glVertex4f(sx, sy, 0, 1);
                glColor3f(1.000, 0.498, 0.314);
                glVertex4f(sx + mx - 1, sy, 0, 1);
                glColor3f(1.000, 0.388, 0.278);
                glVertex4f(sx + mx - 1, sy + my - 1, 0, 1);
                glVertex4f(sx, sy, 0, 1);
                glColor3f(1.000, 0.271, 0.000);
                glVertex4f(sx + mx - 1, sy + my - 1, 0, 1);
                glVertex4f(sx, sy + my - 1, 0, 1);
            glEnd();
        }
};

#endif