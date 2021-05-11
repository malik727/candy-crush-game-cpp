#include "Points.h"

void Points::setX(int x)
{
    this->x = x;
}
void Points::setY(int y)
{
    this->y = y;
}
void Points::setGemType(int gemType)
{
    this->gemType = gemType;
}
int Points::getX()const
{
    return x;
}
int Points::getY()const
{
    return y;
}
int Points::getGemType()const
{
    return gemType;
}
