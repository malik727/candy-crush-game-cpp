#ifndef GEMSHAPE_H
#define GEMSHAPE_H

#include <iostream>

class GemShape
{
    public:
        GemShape()
        {
            //Default Constructor
        }
        virtual void drawGem(int, int) = 0;
};

#endif