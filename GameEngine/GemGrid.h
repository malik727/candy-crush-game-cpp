#ifndef GEMGRID_H
#define GEMGRID_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "../Utilities/util.h"
#include "Points.h"
#include "GemData/TriangleGem.h"
#include "GemData/FrenchGem.h"
#include "GemData/ScissorGem.h"
#include "GemData/SphereGem.h"
#include "GemData/BaguetteGem.h"
#include <iostream>

class GemGrid
{
    private:
        int length;
        int height;
        Points** grid;
        GemShape* gem;              
        static int* oldCoords;
        static bool isSwap;
        static int* swapLineCoords;
        int score;

    public:
        GemGrid()
        {
            length = 0;
            height = 0;
            grid = NULL;
            score = 0;
        }
        GemGrid(int length, int height)
        {
            this->length = length;
            this->height = height;
            grid = new Points*[height];
            for(int i=0; i<height; i++)
            {
                grid[i] = new Points[length];
            }
            score = 0;
        }
        int getLength()const;
        int getHeight()const;
        void setDimensions(int length, int height);
        void initializeRandomly();
        void drawBoard();
        void swapGem(int, int);
        void setNULL();
        void drawSwapLine();
        void cascade();
        int getScore()const;
};

#endif
