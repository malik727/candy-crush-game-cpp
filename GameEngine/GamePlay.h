#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GemGrid.h"
#include <iostream>

class GamePlay
{
    private:
        int levelID;
        int levelMode;
        GemGrid levelGrid;
    public:
        GamePlay()
        {
            levelID = 0;
            levelMode = 0; //0 means default
        }
        GamePlay(int levelID, int levelMode)
        {
            this->levelID = levelID;
            this->levelMode = levelMode;
            if(levelID == 1)
            {
                levelGrid.setDimensions(5, 5);
                levelGrid.initializeRandomly();
            }
            else if(levelID == 2)
            {
                levelGrid.setDimensions(6, 6);
                levelGrid.initializeRandomly();
            }
            else if(levelID == 3)
            {
                levelGrid.setDimensions(7, 7);
                levelGrid.initializeRandomly();
            }
            else if(levelID == 4)
            {
                levelGrid.setDimensions(7, 7);
                levelGrid.initializeRandomly();
            }
        }
        void setLevel(int levelID, int levelMode);
        void start();
        bool checkGem(int, int);
        void resetOldCoords();
        void drawSwapLine();
        int getScore()const;
};

#endif  