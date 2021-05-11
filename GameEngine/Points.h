#ifndef POINTS_H
#define POINTS_H

#include <iostream>

class Points
{
    private:
        int x;
        int y;
        int gemType;
    public:
        Points()
        {
            x = 0;
            y = 0;
            gemType = 0;
        }
        Points(int x, int y, int gemType)
        {
            this->x = x;
            this->y = x;
            this->gemType = gemType;
        }
        int getX()const;
        int getY()const;
        int getGemType()const;
        void setX(int x);
        void setY(int y);
        void setGemType(int gemType);

};
#endif